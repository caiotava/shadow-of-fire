#include "Game.h"
#include "GameClock.h"

#include <spdlog/spdlog.h>
#include <SDL_image.h>

bool Game::Initialize(GameConfig cfg) {
    config = cfg;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        spdlog::error("initializing sdl: " + std::string(SDL_GetError()));
        return false;
    }

    window = SDL_CreateWindow(
            config.title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            config.screenWidth,
            config.screenHeight,
            config.windowFlags
    );

    if (!window) {
        spdlog::error("creating sdl window: " + std::string(SDL_GetError()));
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        spdlog::error("creating sdl renderer: " + std::string(SDL_GetError()));
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        spdlog::error("initializing sdl image for png: " + std::string(IMG_GetError()));
        return false;
    }

    currentScene = new Scene(renderer);

    return true;
}

void Game::RunLoop() {
    isRunning = true;

    currentScene->Initialize();

    while (isRunning) {
        processInput();
        updateGame();
        generateOutput();
    }
}

void Game::processInput() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
}

void Game::updateGame() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + FRAME_TIME_MILLISECONDS));

    float deltaTime = (SDL_GetTicks() - ticksCount) / SECOND_IN_MILLISECONDS;

    if (deltaTime > MAX_DELTA_TIME_MILLISECONDS) {
        deltaTime = MAX_DELTA_TIME_MILLISECONDS;
    }

    ticksCount = SDL_GetTicks();

    currentScene->Update(deltaTime);
}

void Game::generateOutput() {
    currentScene->Render();
}

void Game::Shutdown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
