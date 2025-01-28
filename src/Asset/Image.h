#ifndef IMAGE_H
#define IMAGE_H

#include "Asset.h"
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
namespace Gkit{
class Image : public Asset{
public:
    /**
     * @brief Image Constructor
     * @author Cora
     * @since Version 0.10
     * @param file_path -- the path of the image file what you want to load
     * @return void
     */
    Image(std::string file_path);
    ~Image();

    /**
     * @brief GetTexture -- get the texture of the image
     * @author Cora
     * @since Version 0.10
     * @return std::shared_ptr<SDL_Texture> -- the texture of the image
     * @note the texture is a shared pointer to the texture of the image
     */
    std::shared_ptr<SDL_Texture> GetTexture() const;
    
private:
    std::shared_ptr<SDL_Texture>image_texture;

private:
    /**
     * @brief Image CheckSubsystemInitState
     * @author Cora
     * @since Version 0.10
     * @param flags -- SDL_IMG_InitFlags
     * @return int
     * 
     * @note This is a private function belonging Window class
     * 
     * If SDL IMG subsystem what we need is init, it will return 0.
     * 
     * Otherwise, it will return the result that is provide by IMG_Init. 
     */
    int CheckSubsystemInitState(IMG_InitFlags flag);
};// class Image

} // namespace Gkit


#endif