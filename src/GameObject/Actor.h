#ifndef ACTOR_H
#define ACTOR_H

#include "../Vector2.h"
#include "../Asset/Sprite.h"

namespace Gkit{

class Actor{
public:
    Actor();
    ~Actor() = default;
    
private:
    Vector2 actorPosition = {0.0f, 0.0f};
    Sprite actorSprite;
};

}// namespace Gkit

#endif// ACTOR_H