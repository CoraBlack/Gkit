#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>

#include "Pawn.h"
#include "../Graphics/Camera.h"
#include "../Controller/PlayerController.h"

namespace Gkit{

class Character : public Pawn{
public:
    
private:
    std::shared_ptr<Camera> camera;
    PlayerController        player_Controller;    
}; // class Character

} // namespace Gkit

#endif // CHARACTER_H