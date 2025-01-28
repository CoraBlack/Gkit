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

/// @brief Base class of user interface
class Scenario{
public:
    Scenario()  = default;
    ~Scenario() = default;

private:
    /**
     * @brief Its type is a unordered map, which key is the position in the grid, and value is the texture of the grid.
     * The position in the grid is a Vector2, which x is the column index, and y is the row index.
     * The texture of the grid is a SDL_Texture, which is a unique pointer to the texture.
     * It is only use for user 2D interface, so it is different from the grid structure where Sprite classes are stored. The difference is that it has no multi-level data structure
     */
    std::unordered_map<Gkit::Vector2, std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>> shown_grid;
};

}// namespace Gkit

#endif