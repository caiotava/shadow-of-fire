#ifndef SHADOW_OF_FIRE_GAME_H
#define SHADOW_OF_FIRE_GAME_H

#include <string>
#include "Scene.h"

#include <SDL.h>

typedef struct {
    std::string title;
    int screenWidth;
    int screenHeight;
    int windowFlags;
} GameConfig;

class Game {
public:
    Game() = default;

    bool Initialize(GameConfig config);
    void RunLoop();
    void Shutdown();

private:
    bool isRunning;
    uint32_t ticksCount;

    GameConfig config;

    SDL_Window *window;
    SDL_Renderer *renderer;

    Scene *currentScene;

    void processInput();
    void updateGame();
    void generateOutput();
};


#endif //SHADOW_OF_FIRE_GAME_H
