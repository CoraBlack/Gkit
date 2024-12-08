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
#include "Camera.h"
namespace Gkit{

class Window{
public:
    Window(const char* win_title,
            int win_pos_x, int win_pos_y,
            int win_w, int win_h 
            );
    ~Window();

    void HideWindow();
    void ShowWindow();
    void SetWindowFullScreen();
    void LimitWindowSize(int w, int h);
    void RemoveLimitWindowSize();

private:
    bool isLimitWindowSize = false;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>win_ptr;
}; // class Window

}// namespace Gkit
#endif