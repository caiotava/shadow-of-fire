#include "Game.h"

#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {
    Game game;
    GameConfig config = {
            .title = "Shadow of Fire",
            .screenWidth = 800,
            .screenHeight = 600,
            .windowFlags = SDL_WINDOW_SHOWN,
    };

    if (!game.Initialize(config)) {
        spdlog::critical("error to initialize the game class");
        return 1;
    }

    game.RunLoop();
    game.Shutdown();

    return 0;
}
