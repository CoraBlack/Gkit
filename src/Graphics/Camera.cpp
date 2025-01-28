#include "Camera.h"

/// Constructor and Destructor ///
Gkit::Camera::Camera(SDL_Window* win) : camera_renderer(nullptr, SDL_DestroyRenderer){
    SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    return;
}
Gkit::Camera::Camera(SDL_Renderer* renderer) : camera_renderer(renderer, SDL_DestroyRenderer){
    return;
}
Gkit::Camera::~Camera(){
    SDL_DestroyRenderer(this->camera_renderer.get());
    return;
}

/// Getter ///
auto Gkit::Camera::GetRenderer() const{
    return this->camera_renderer.get();
}

/// Setter ///


/// Operation functions ///
void Gkit::Camera::ShowImage(Image& img, int x, int y, int w, int h){
    if (!img.IsAvailiable()) return;
    SDL_RenderCopy(this->camera_renderer.get(), img.GetTexture().get(), nullptr, nullptr);
    SDL_RenderPresent(this->camera_renderer.get());
    SDL_Delay(3000);
    return;    
}
