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
#include <functional>
#include <SDL2/SDL.h>
#include "Camera.h"
namespace Gkit{

#define WINDOW_CENTER SDL_WINDOWPOS_CENTERED

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
    void ShowImage(Image& img, int layerIndex = 0);

private:
    bool isLimitWindowSize = false;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>win_ptr;
    Camera camera;

private:
    void HandleWindowEvents();
}; // class Window

}// namespace Gkit
#endif