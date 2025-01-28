#include "Sprite.h"

/// Sprite Constructor ///
Gkit::Sprite::Sprite(std::vector<ImgInfo> new_imgs){
    for (auto& img : new_imgs){
        // Check if the image is already in the sprite
        if(!img.img->IsAvailiable()){
            continue;
        }
        // Check if the layer index is valid
        if(img.layer_index > this->layers_of_img.size()){
            this->layers_of_img.resize(img.layer_index + 1);
            this->layers_of_img[img.layer_index].push_back(std::make_shared<ImgInfo>(img));
            continue;
        }
        // If the layer index is valid, add the image to the image layer
        this->layers_of_img[img.layer_index].push_back(std::make_shared<ImgInfo>(img));
    }
    return;
}


/// Operation Function ///
int Gkit::Sprite::AddNewImage(ImgInfo new_image){
    if (!new_image.img->IsAvailiable()){
        return -1;  // Image is unavailiable
    }

    if (new_image.layer_index > this->layers_of_img.size()){
        this->layers_of_img.resize(new_image.layer_index + 1);
    }

    this->layers_of_img[new_image.layer_index].push_back(std::make_shared<ImgInfo>(new_image));

    return 0;  // Success
}

int Gkit::Sprite::InsertNewLayer(int layer_index){
    if (layer_index < -1){
        return -1;
    }

    if (layer_index > this->layers_of_img.size()){
        this->layers_of_img.resize(layer_index + 1);
        return 0;  // Success
    }
    this->layers_of_img.insert(this->layers_of_img.begin() + layer_index, std::vector<std::shared_ptr<ImgInfo>>());
    for (int i = layer_index + 1; i < this->layers_of_img.size(); ++i){
        for(auto& img : this->layers_of_img[i]){
            img->layer_index += 1;
        }
    }
    return 0;  // Success
}