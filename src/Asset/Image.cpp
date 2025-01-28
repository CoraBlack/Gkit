#include "Image.h"
#include <functional>

Gkit::Image::Image(std::string file_path) : image_texture(nullptr, SDL_DestroyTexture), Gkit::Asset::Asset(file_path){
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

std::shared_ptr<SDL_Texture> Gkit::Image::GetTexture() const {
    return this->image_texture;
}

int Gkit::Image::CheckSubsystemInitState(IMG_InitFlags flags){
    if (!SDL_WasInit(flags)){
        return IMG_Init(flags);
    }
    return 0;
}