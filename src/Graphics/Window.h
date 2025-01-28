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

#define WINDOW_CENTER SDL_WINDOWPOS_CENTERED

class Window{
public:
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
    Window(const char* win_title,
            int win_pos_x, int win_pos_y,
            int win_w, int win_h 
            );

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
    ~Window();

    /// Window Setting functions ///

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
    void HideWindow();
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
    void ShowWindow();
    /**
     * Window SetWindowFullScreen
     * @author Cora
     * @since Version 0.10
     * @param None
     * @return Void
     * 
     * Set your game window full screen
     */
    void SetWindowFullScreen();
    /**
     * Window LimitWindowSize
     * @author Cora
     * @since Version 0.10
     * @param None
     * @return Void
     * 
     * Set your game window Limited and limited size
     */
    void LimitWindowSize(int w, int h);

    
    /**
     * @note unenforced
     */
    void RemoveLimitWindowSize();
    /**
     * Window ShowImage
     * @author Cora
     * @since Version 0.10
     * @param None
     * @return Void
     * Show your game window
     */
    void ShowImage(Image& img, int x, int y, int w, int h);

private:
    bool isLimitWindowSize = false;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>win_ptr;
    std::unique_ptr<Camera>                                  target_camera;
private:
    void HandleWindowEvents();
}; // class Window

}// namespace Gkit
#endif