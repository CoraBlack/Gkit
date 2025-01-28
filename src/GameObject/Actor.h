#ifndef ACTOR_H
#define ACTOR_H

#include "../Vector2.h"
#include "../Sprite/Sprite.h"

namespace Gkit{

class Actor{
public:
    Actor();
    ~Actor() = default;
    
    Vector2 GetPosition() const;
    
private:
    Sprite  sprite;
    Vector2 position = {0.0f, 0.0f};
};

}// namespace Gkit

#endif// ACTOR_H