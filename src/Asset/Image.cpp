#include "Image.h"
#include <functional>

/**
 * Image constructor
 * @author Cora
 * @since Version 0.10
 * @param filePath -- string
 * @return void
 * 
 * 
 */
Gkit::Image::Image(std::string filePath) : imageTexture(nullptr, SDL_DestroyTexture), Gkit::Asset::Asset(filePath){
    // Determine the file type
    if (this->GetFileFormat() == "jpg"){
        this->CheckSubsystemInitState(IMG_INIT_JPG);
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

Gkit::Image::~Image(){
    
    return;
}

/**
 * Image CheckSubsystemInitState
 * @author Cora
 * @since Version 0.10
 * @param flags --IMG_InitFlags
 * @return int
 * 
 * This is a private function belonging Window class
 * 
 * If SDL IMG subsystem what we need is init, it will return 0.
 * 
 * Otherwise, it will return the result that is provide by IMG_Init. 
 */
int Gkit::Image::CheckSubsystemInitState(IMG_InitFlags flags){
    if (!SDL_WasInit(flags)){
        return IMG_Init(flags);
    }
    return 0;
}

std::shared_ptr<SDL_Texture> Gkit::Image::GetTexture() const {
    return this->imageTexture;
}
