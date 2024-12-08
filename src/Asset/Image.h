#ifndef IMAGE_H
#define IMAGE_H

#include "Asset.h"
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
namespace Gkit{
class Image : public Asset{
public:
    Image(std::string filePath);
    ~Image();

    std::shared_ptr<SDL_Texture> GetTexture() const;
    
private:
    std::shared_ptr<SDL_Texture>imageTexture;

private:
    int CheckSubsystemInitState(IMG_InitFlags flag);
};// class Image

} // namespace Gkit


#endif