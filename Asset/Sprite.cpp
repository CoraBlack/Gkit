#include "Sprite.h"
#include <functional>

/**
 * Sprite constructor
 * @author Cora
 * @since Version 0.10
 * @param filePath -- string
 * @return void
 * 
 * 
 */
Gkit::Sprite::Sprite(std::string filePath) : spriteTexture(nullptr, SDL_DestroyTexture), Gkit::Asset::Asset(filePath){
    // Determine the file type
    if (this->GetFileFormat() == "jpg"){
        this->CheckSubsystemInitState(IMG_INIT_PNG);
        return;        
    }

    if (this->GetFileFormat() == "png"){
        this->CheckSubsystemInitState(IMG_INIT_PNG);
        return;
    }

    if (this->GetFileFormat() == "tif"){
        this->CheckSubsystemInitState(IMG_INIT_TIF);
        return;
    }

    if (this->GetFileFormat() == "webp"){
        this->CheckSubsystemInitState(IMG_INIT_WEBP);
        return;
    }

    if (this->GetFileFormat() == "jxl"){
        this->CheckSubsystemInitState(IMG_INIT_JXL);
        return;
    }

    if (this->GetFileFormat() == "avif"){
        this->CheckSubsystemInitState(IMG_INIT_AVIF);
        return;
    }

    // If File type is unavailiable
    this->ClearFilePath();
    return;
}

Gkit::Sprite::~Sprite(){
    SDL_DestroyTexture(this->spriteTexture.get());
    this->spriteTexture.reset(nullptr);
    return;
}

/**
 * Sprite CheckSubsystemInitState
 * @author Cora
 * @since Version 0.10
 * @param flags --IMG_InitFlags
 * @return int
 * 
 * If SDL IMG subsystem what we need is init, it will return 0.
 * 
 * Otherwise, it will return the result that is provide by IMG_Init. 
 */
int Gkit::Sprite::CheckSubsystemInitState(IMG_InitFlags flags){
    if (!SDL_WasInit(flags)){
        return IMG_Init(flags);
    }
    return 0;
}