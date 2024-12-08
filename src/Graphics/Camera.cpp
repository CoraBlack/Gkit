#include "Camera.h"

Gkit::Camera::Camera(SDL_Window* win) : cameraRenderer(nullptr, SDL_DestroyRenderer){
    SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    return;
}

Gkit::Camera::~Camera(){
    SDL_DestroyRenderer(this->cameraRenderer.get());
    return;
}

void Gkit::Camera::ShowImage(Image& img, int x, int y, int w, int h){
    if (!img.IsAvailiable()) return;

    SDL_RenderCopy(this->cameraRenderer.get(), img.GetTexture().get(), nullptr, nullptr);
    SDL_RenderPresent(this->cameraRenderer.get());
    return;    
}
