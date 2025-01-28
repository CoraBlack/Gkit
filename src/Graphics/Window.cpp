#include <utility>
#include <thread>

#include "../GkitSetting.h"
#include "Window.h"

Gkit::Window::Window(const char* win_title, int win_pos_x, int win_pos_y, int win_w, int win_h)
    : win_ptr(SDL_CreateWindow(win_title, win_pos_x, win_pos_y, win_w, win_h, SDL_WINDOW_SHOWN), SDL_DestroyWindow) {    
    // Check SDL Video modle whether work
    if (!SDL_WasInit(SDL_INIT_VIDEO)){
        SDL_Init(SDL_INIT_VIDEO);
        return;
    }
    this->target_camera = std::make_unique<Camera>(this->win_ptr.get());
}

Gkit::Window::~Window(){        
    return;
}

void Gkit::Window::HideWindow(){
    if (SDL_GetWindowFlags(this->win_ptr.get()) == SDL_WINDOW_HIDDEN){
        return;
    }
    SDL_HideWindow(this->win_ptr.get());
    return;
}

void Gkit::Window::ShowWindow(){
    if (SDL_GetWindowFlags(this->win_ptr.get()) == SDL_WINDOW_HIDDEN){
        SDL_ShowWindow(this->win_ptr.get());
        return;
    }
    return;
}

void Gkit::Window::SetWindowFullScreen(){
    if (SDL_GetWindowFlags(this->win_ptr.get()) == SDL_WINDOW_FULLSCREEN){
        return;
    }
    SDL_SetWindowFullscreen(this->win_ptr.get(), SDL_WINDOW_FULLSCREEN);
    return;
}
 
void Gkit::Window::LimitWindowSize(int w, int h){
    if (SDL_GetWindowFlags(this->win_ptr.get()) == SDL_WINDOW_RESIZABLE){
        
    }
}

void Gkit::Window::RemoveLimitWindowSize(){
    return; // Not implemented
}

void Gkit::Window::HandleWindowEvents(){
}

void Gkit::Window::ShowImage(Image& img, int x, int y, int w, int h){
    if (this->target_camera == nullptr){
        auto* renderer_temp = SDL_CreateRenderer(this->win_ptr.get(), -1, SDL_RENDERER_ACCELERATED);
        SDL_RenderCopy(renderer_temp, img.GetTexture().get(), NULL, NULL);
        SDL_RenderPresent(renderer_temp);
        SDL_Delay(3000);
        SDL_DestroyRenderer(renderer_temp);
        return;
    }
    this->target_camera->ShowImage(img, x, y, w, h);
    return;
}