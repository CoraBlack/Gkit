#ifndef SPRITE_H
#define SPRITE_H

#include "Asset.h"
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
namespace Gkit{
class Sprite : public Asset{
public:
    Sprite(std::string filePath);
    ~Sprite();

    
private:
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>spriteTexture;

private:
    int CheckSubsystemInitState(IMG_InitFlags flag);
};// class Sprite

} // namespace Gkit


#endif