#ifndef SPRITE_H
#define SPRITE_H

#include "Asset.h"
#include <memory>
#include <SDL2/SDL.h>
namespace Gkit{
class Sprite : public Asset{
public:
    Sprite(std::string filePath);
    ~Sprite();

    
private:
    std::unique_ptr<SDL_Texture>spriteTexture = nullptr;
};// class Sprite

} // namespace Gkit


#endif