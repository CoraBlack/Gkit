#include "Window.h"

Gkit::Window::Window(const char* win_title, int win_pos_x, int win_pos_y, int win_x, int win_y){
    // Check SDL Video modle whether work
    if (!SDL_WasInit(SDL_INIT_VIDEO)){
        return;
    }
    // Create a window and reset win_ptr
    this->win_ptr.reset(SDL_CreateWindow(win_title, win_pos_x, win_pos_y, win_x, win_y, SDL_WINDOW_RESIZABLE));
    this->title = win_title;
    return;
}

Gkit::Window::~Window(){
    SDL_DestroyWindow(this->win_ptr.get());
    this->win_ptr.reset(nullptr);
    return;
}