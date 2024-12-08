#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include <memory>

#include "Image.h"
#include "../Vector2.h"
namespace Gkit{

struct ImgInfo{
    Vector2 imgPos;
    std::shared_ptr<Image>img;
    unsigned int layerIndex = 0; // The higher the number, the lower the layer. Zero layer is the top.
};

class Sprite{
public:
    Sprite()  = default;
    Sprite(std::vector<ImgInfo> newImgs);
    ~Sprite() = default;

    int AddNewImage(ImgInfo newImage);
    int InsertNewLayer(unsigned int layerIndex);

private:
    std::vector<std::vector<std::shared_ptr<ImgInfo>>> layersOfImg;
};// class sprite

}// namespace Gkit
#endif// SPRITE_H