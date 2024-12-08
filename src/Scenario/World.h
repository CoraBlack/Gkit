#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <unordered_map>

#include "Scenario.h"
#include "../GameObject/Actor.h"

namespace Gkit{

class World : public Scenario{
public:
    World() = default;
    ~World() = default;

private:
    std::unordered_map<Vector2, std::vector<Actor>> actorBlockMap;
};

} // namespace Gkit


#endif // WORLD_H