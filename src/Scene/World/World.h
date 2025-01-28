#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <variant>
#include <type_traits>
#include <unordered_map>

#include "WorldMode.h"
#include "../Graphics/Window.h"
#include "../GameObject/Actor.h"
#include "../GameObject/Pawn.h"
#include "../GameObject/Character.h"

using T_WorldBlock = std::vector<std::unique_ptr<std::variant<Gkit::Actor, Gkit::Pawn, Gkit::Character>>>;


namespace Gkit{

class World{
public:
    /**
     * @brief World constructor more with actors vector args and mainObject shared ptr.
     * @author Cora
     * @since Version 0.20
     * @param win -- Window to draw on.
     * @param addActors -- Vector actors to add to the world.
     * @param mainObject -- Main object to control, default is nullptr.
     * @param mainCamera -- Main camera to draw on, default is nullptr.
     * @return Void
     * @note This constructor is used to add actors to the world.
     */
    World(std::shared_ptr<Window> win, std::vector<std::variant<Actor, Pawn, Character>>& add_actors, std::shared_ptr<Pawn> main_object , std::shared_ptr<Camera> main_camera);
    ~World() = default;

    /// Insert function with variant arg.
    /**
     * @brief Insert an object to the world.
     * @author Cora
     * @since Version 0.20
     * @param obj_var -- Object to insert.
     * @return Void
     * @note This function is used to insert an object to the world.You need provide a variant object.
     */
    void Insert(std::variant<Actor, Pawn, Character>& obj_var);
    /**
     * @brief Insert a vector of variant objects to the world.
     * @author Cora
     * @since Version 0.20
     * @param objs_var -- Vector of variant objects to insert.
     * @return Void
     * @note This function is used to insert a vector of variant objects to the world.
     */
    void Insert(std::vector<std::variant<Actor, Pawn, Character>>& objs_var);

    /// Insert function with native object reference type arg.
    template<typename Tp_Ins, typename = std::enable_if_t<std::disjunction_v<std::is_same<Tp_Ins, Actor>, std::is_same<Tp_Ins, Pawn>, std::is_same<Tp_Ins, Character>>>>
    /**
     * @brief Insert a native object reference type to the world.
     * @author Cora
     * @since Version 0.20
     * @param obj -- Object to insert.
     * @return Void
     * @note This function is used to insert a native object reference type to the world.
     * It should be Actor or Pawn or Character type obj.
     */
    void Insert(Tp_Ins& obj) { 
        
        return;
    }
    template<typename Tp_Ins, typename = std::enable_if_t<std::disjunction_v<std::is_same<Tp_Ins, Actor>, std::is_same<Tp_Ins, Pawn>, std::is_same<Tp_Ins, Character>>>>
    /**
     * @brief Insert a native object reference type to the world.
     * @author Cora
     * @since Version 0.20
     * @param objs -- Vector of native object reference type to insert.
     * @return Void
     * @note This function is used to a vector of native object reference type to insert to the world.
     * It should be a vector with Actor or Pawn or Character type.
     */
    void Insert(std::vector<Tp_Ins>& objs){
        for(auto& i : objs){
            
        }
        return;
    }

    virtual void Update(float dt);

private:
    int                                       world_block_size = 64;
    WorldMode                                 mode;
    std::unordered_map<Vector2, T_WorldBlock> actor_block_map;
};

} // namespace Gkit


#endif // WORLD_H