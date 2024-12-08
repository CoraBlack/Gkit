#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include <memory>

#include "../Asset/Image.h"
#include "../Asset/Sprite.h"
namespace Gkit{

class Camera{
public:
    Camera(SDL_Window* win);
    ~Camera();

    void ShowImage (Image& img, int x, int y, int w, int h);
    void ShowSprite(Sprite sprite);
private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>cameraRenderer;
};

}// namespace Gkit

#endif // CAMERA_H