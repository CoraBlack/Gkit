#include "Sprite.h"

/**
 * Constructor for the Sprite class.
 * @since Version 1.20
 * @anchor Cora
 * @param newImgs A vector of ImgInfo objects that represent the images to be added to the sprite.
 * @return void
 * 
 * This constructor takes a vector of ImgInfo objects and adds them to the sprite.
 * It first checks if the image is already in the sprite, adds it to the appropriate layer.
 * 
 * If the layer index is invalid, it resizes the layersOfImg vector to the appropriate size.
 * It then adds the image to the appropriate layer.
 */
Gkit::Sprite::Sprite(std::vector<ImgInfo> newImgs){
    for (auto& img : newImgs){
        // Check if the image is already in the sprite
        if(!img.img->IsAvailiable()){
            continue;
        }

        // Check if the layer index is valid
        if(img.layerIndex > this->layersOfImg.size()){
            this->layersOfImg.resize(img.layerIndex + 1);
            this->layersOfImg[img.layerIndex].push_back(std::make_shared<ImgInfo>(img));
            continue;
        }
        // If the layer index is valid, add the image to the image layer
        this->layersOfImg[img.layerIndex].push_back(std::make_shared<ImgInfo>(img));
    }

    return;
}


/**
 * Sprite AddNewImage function.
 * @since Version 1.20
 * @anchor Cora
 * @param newImage An ImgInfo object that represents the image to be added to the sprite.
 * @return int Returns 0 if the image was successfully added, -1 if the image is unavailiable.
 * 
 * This function adds a new image to the sprite. It first checks if the image is already in the sprite,
 * 
 * And check the layer index is whether bigger than the current size of the layersOfImg vector.
 * If it is bigger, it resizes the layersOfImg vector to the appropriate size.
 * It then adds the image to the appropriate layer.
 * 
 * Otherwise, it adds the image to the appropriate layer and returns 0.
 */
int Gkit::Sprite::AddNewImage(ImgInfo newImage){
    if (!newImage.img->IsAvailiable()){
        return -1;  // Image is unavailiable
    }

    if (newImage.layerIndex > this->layersOfImg.size()){
        this->layersOfImg.resize(newImage.layerIndex + 1);
    }

    this->layersOfImg[newImage.layerIndex].push_back(std::make_shared<ImgInfo>(newImage));

    return 0;  // Success
}


int Gkit::Sprite::InsertNewLayer(unsigned int layerIndex){
    if (layerIndex > this->layersOfImg.size()){
        this->layersOfImg.resize(layerIndex + 1);
        return 0;  // Success
    }

    this->layersOfImg.insert(this->layersOfImg.begin() + layerIndex, std::vector<std::shared_ptr<ImgInfo>>());

    for (int i = layerIndex + 1; i < this->layersOfImg.size(); ++i){
        for(auto& img : this->layersOfImg[i]){
            img->layerIndex += 1;
        }
    }
    return 0;  // Success
    
}