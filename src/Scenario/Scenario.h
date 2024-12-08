/**
 * Scenario.h
 * This file define the base class Scenario.It use to decribe the 
 * scene what the program should show in the screen.
 * 
 */

#ifndef SCENARIO_H
#define SCENARIO_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>

#include "../Vector2.h"

namespace Gkit{

class Scenario{
public:
    Scenario();
    ~Scenario();

private:
    /**
     * About grid:
     * 
     */
    std::unordered_map<Gkit::Vector2, std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>> shownGrid;
};

}// namespace Gkit

#endif