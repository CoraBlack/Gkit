#include "Window.h"
#include <utility>
/**
 *  Window Constructor
 * 
 *  @author Cora
 *  @since Version 0.10
 *  @param win_title window's title.
 *  @param win_pos_x x position of window in screen
 *  @param win_pos_y y position of window in screen
 *  @param win_w weight size of window
 *  @param win_h height size of window
 *  @returns void
 * 
 *  This is the constructor of window class.
 *  
 *  When it is ready to create a window, it firstly check SDL_INIT_VIDEO whether work.
 * 
 *  After that, it will reset the win_ptr with the fuction that use to create in SDL.
*/
Gkit::Window::Window(const char* win_title, int win_pos_x, int win_pos_y, int win_w, int win_h) : win_ptr(nullptr, SDL_DestroyWindow){
    // Check SDL Video modle whether work
    if (!SDL_WasInit(SDL_INIT_VIDEO)){
        return;
    }
    // Create a window and reset win_ptr
    this->win_ptr.reset(SDL_CreateWindow(win_title, win_pos_x, win_pos_y, win_w, win_h, SDL_WINDOW_RESIZABLE));
    return;
}


/** 
 * Window Destructors
 * 
 * @author Cora
 * @since Version 0.10
 * @param void
 * @return void
 * 
 * This is the destructor of class window.
 * 
 * It will destroy the SDL_window and free momory
 * and set win_ptr to nullptr.
 */
Gkit::Window::~Window(){
    SDL_DestroyWindow(this->win_ptr.get());
    this->win_ptr.reset(nullptr);
    return;
}


/**
 * Window HideWindow
 * @author Cora
 * @since Version 0.10
 * @param None
 * @return Void
 * 
 * Hide your game window
 * 
 * Firstly, it will check the SDl_WindowsFlags of your window.
 * If it is hidden and will not work.
 */
void Gkit::Window::HideWindow(){
    if (SDL_GetWindowFlags(this->win_ptr.get()) == SDL_WINDOW_HIDDEN){
        return;
    }
    SDL_HideWindow(this->win_ptr.get());
    return;
}

/**
 * Window ShowWindow
 * @author Cora
 * @since Version 0.10
 * @param None
 * @return Void
 * 
 * Show your game window
 * 
 * Firstly, it will check the SDl_WindowsFlags of your window.
 * If it is shown and will not work.
 */
void Gkit::Window::ShowWindow(){
    if (SDL_GetWindowFlags(this->win_ptr.get()) == SDL_WINDOW_HIDDEN){
        SDL_ShowWindow(this->win_ptr.get());
        return;
    }
    return;
}


/**
 * Window SetWindowFullScreen
 * @author Cora
 * @since Version 0.10
 * @param None
 * @return Void
 * 
 * Set your game window full screen
 */
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