/*
    Window.h
    Writed by @Cora

    This file define class window.
    It is the container of all the graphics object.

*/
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>
#include <memory>

namespace Gkit{

class Window{
public:
    Window(const char* win_title, // Window title
            int win_pos_x, int win_pos_y, // Window position where show
            int win_x, int win_y // Window size
            );
    ~Window();
private:
    std::string title = "";
    std::unique_ptr<SDL_Window>win_ptr = nullptr;
}; // class Window

}// namespace Gkit
#endif