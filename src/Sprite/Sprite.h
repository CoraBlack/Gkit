#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include <memory>

#include "../Asset/Image.h"
#include "../Vector2.h"
namespace Gkit{

/// @brief A struct that represents an image and its position and layer index.
struct ImgInfo{
    Vector2 img_pos;
    std::shared_ptr<Image>img;
    unsigned int layer_index = 0; // The higher the number, the lower the layer. Zero layer is the top.
};

/// @brief A class that represents a sprite.In essence, it is a special collection of images
/// 
/// It is the basic render objects for the game.
class Sprite{
public:
    /// @brief Default constructor for the Sprite class.
    Sprite()  = default;
    /**
     * @brief Constructor for the Sprite class.
     * @since Version 0.12
     * @anchor Cora
     * @param new_imgs A vector of ImgInfo objects that represent the images to be added to the sprite.
     * @return void
     */
    Sprite(std::vector<ImgInfo> new_imgs);
    /// @brief Destructor for the Sprite class.
    ~Sprite() = default;

    /**
     * @brief Add a new image to the sprite.
     * @since Version 0.12
     * @anchor Cora
     * @param new_image --An ImgInfo object that represents the image to be added to the sprite.
     * @return int --Returns 0 if the image was successfully added, -1 if the image is unavailiable.
     */
    int AddNewImage(ImgInfo new_image);
    /**
     * @brief Insert a new layer into the sprite.
     * @since Version 0.12
     * @anchor Cora
     * @param layer_index --The index where the new layer will be inserted.
     * @return int --Returns 0 if the layer was successfully inserted, -1 if the layer index is invalid.
     */
    int InsertNewLayer(int layer_index);
    /**
     * @brief Get texture of sprite.
     * @since Version 0.20
     * @anchor Cora
     * @return SDL_Texture --Returns the number of layers in the sprite.
     */
    // auto GetImages() const;

private:
    std::vector<std::vector<std::shared_ptr<ImgInfo>>> layers_of_img;
};// class sprite

}// namespace Gkit
#endif// SPRITE_H