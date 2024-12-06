/*
    Window.h
    Writed by @Cora

    This file define class window.
    It is the container of all the graphics object.
    Actually, it is just encapsula SDL_Window easily.
    To make it easier to use and call.
    So, I can't avoid to decrease the args of constructor.
*/
#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>

namespace Gkit{

class Window{
public:
    Window(const char* win_title,
            int win_pos_x, int win_pos_y,
            int win_w, int win_h 
            );
    ~Window();

    void SetWindowFullScreen();
    void HideWindow();
    void ShowWindow();
private:
    std::unique_ptr<SDL_Window>win_ptr;
}; // class Window

}// namespace Gkit
#endif