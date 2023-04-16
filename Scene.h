#ifndef SHADOW_OF_FIRE_SCENE_H
#define SHADOW_OF_FIRE_SCENE_H

#include "SDL.h"

class Scene {
public:
    Scene(SDL_Renderer *renderer);

    bool Initialize();
    bool Update(float deltaTime);
    bool Render();

private:
    SDL_Renderer *renderer;
};


#endif //SHADOW_OF_FIRE_SCENE_H
