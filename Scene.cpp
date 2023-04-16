#include "Scene.h"

#include <SDL_image.h>

SDL_Texture *playerTexture;
SDL_Rect playerPos;
SDL_Rect wall1;
SDL_Rect wall2;

Scene::Scene(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

bool Scene::Initialize() {
    playerTexture = IMG_LoadTexture(this->renderer, "assets/player.png");

    playerPos = {
            .x = 130,
            .y = 130,
            .w = 24 * 2,
            .h = 28 * 2
    };

    wall1 = {
            .x = 20,
            .y = 20,
            .w = 50,
            .h = 50
    };

    wall2 = {
            .x = 220,
            .y = 220,
            .w = 50,
            .h = 50
    };

    return true;
}

bool Scene::Update(float deltaTime) {
    return true;
}

bool Scene::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 150, 150, 0);
    SDL_RenderDrawRect(renderer, &wall1);
    SDL_RenderDrawRect(renderer, &wall2);

    SDL_SetRenderDrawColor(renderer, 0, 150, 60, 0);
    for (int i = 0; i < 360; i = i + 20) {
        SDL_Rect line = {
                .x = playerPos.x + playerPos.w / 2,
                .y = playerPos.y + playerPos.h / 2,
                .w = 300,
                .h = 5
        };

        SDL_RenderDrawLine()
    }


    SDL_Rect spriteSrc = {.x = 0, .y = 0, .w = 24, .h = 28};
    SDL_RenderCopy(renderer, playerTexture, &spriteSrc, &playerPos);
    SDL_RenderPresent(renderer);

    return true;
}
