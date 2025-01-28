#include "World.h"
#include <functional>

void Gkit::World::Update(float dt) {
    return;
}

Gkit::World::World(std::shared_ptr<Window> win, std::vector<std::variant<Actor, Pawn, Character>>& add_actors, std::shared_ptr<Pawn> main_object, std::shared_ptr<Camera> main_camera)
    : mode(win, main_object, main_camera) {
    // Add object to block
    this->Insert(add_actors);
    if (main_object == nullptr){ // If the main object is nullptr(default value)
        // Pass
    } else {
        this->mode.SetControlObject(main_object);
    }
    if (main_camera == nullptr){ // If the main camera is nullptr(default value)
        // Pass
    } else {
        this->mode.SetMainCamera(main_camera);
    }
    return;
}

using T_ObjectInBlockWithoutUnique = std::variant<Gkit::Actor, Gkit::Pawn, Gkit::Character>;

void Gkit::World::Insert(std::variant<Actor, Pawn, Character>& obj_var) {
    if constexpr (std::is_same_v<std::decay_t<decltype(obj_var)>, Actor>){
            auto& object = std::get<Actor>(obj_var);
            Vector2 obj_pos = Vector2(object.GetPosition().x / this->world_block_size, object.GetPosition().y / this->world_block_size);
            // Check if the target block is available
            if (this->actor_block_map.find(obj_pos) == this->actor_block_map.end()){
                // Add the object to the block
                this->actor_block_map[obj_pos].emplace_back(std::vector<std::unique_ptr<T_ObjectInBlockWithoutUnique>>{std::make_unique<T_ObjectInBlockWithoutUnique>(object)});
                return;
            }
            this->actor_block_map.at(obj_pos).emplace_back(std::make_unique<T_ObjectInBlockWithoutUnique>(object));
        } else if constexpr (std::is_same_v<std::decay_t<decltype(obj_var)>, Pawn>){
            auto& object = std::get<Pawn>(obj_var);
            Vector2 obj_pos = Vector2(object.GetPosition().x / this->world_block_size, object.GetPosition().y / this->world_block_size);
            // Check if the target block is available
            if (this->actor_block_map.find(obj_pos) == this->actor_block_map.end()){
                // Add the object to the block
                this->actor_block_map[obj_pos].emplace_back(std::vector<std::unique_ptr<T_ObjectInBlockWithoutUnique>>{std::make_unique<T_ObjectInBlockWithoutUnique>(object)});
                return;
            }
            this->actor_block_map.at(obj_pos).emplace_back(std::make_unique<T_ObjectInBlockWithoutUnique>(object));
        } else if constexpr (std::is_same_v<std::decay_t<decltype(obj_var)>, Character>){
            auto& object = std::get<Character>(obj_var);
            Vector2 obj_pos = Vector2(object.GetPosition().x / this->world_block_size, object.GetPosition().y / this->world_block_size);
            // Check if the target block is available
            if (this->actor_block_map.find(obj_pos) == this->actor_block_map.end()){
                // Add the object to the block
                this->actor_block_map[obj_pos].emplace_back(std::vector<std::unique_ptr<T_ObjectInBlockWithoutUnique>>{std::make_unique<T_ObjectInBlockWithoutUnique>(object)});
                return;
            }
            this->actor_block_map.at(obj_pos).emplace_back(std::make_unique<T_ObjectInBlockWithoutUnique>(object));
        }
}

void Gkit::World::Insert(std::vector<std::variant<Actor, Pawn, Character>>& objs_var){
    for(auto& i : objs_var){
        if constexpr (std::is_same_v<std::decay_t<decltype(i)>, Actor>){
            auto& object = std::get<Actor>(i);
            Vector2 obj_pos = Vector2(object.GetPosition().x / this->world_block_size, object.GetPosition().y / this->world_block_size);
            // Check if the target block is available
            if (this->actor_block_map.find(obj_pos) == this->actor_block_map.end()){
                // Add the object to the block
                this->actor_block_map[obj_pos].emplace_back(std::vector<std::unique_ptr<T_ObjectInBlockWithoutUnique>>{std::make_unique<T_ObjectInBlockWithoutUnique>(object)});
                continue;
            }
            this->actor_block_map.at(obj_pos).emplace_back(std::make_unique<T_ObjectInBlockWithoutUnique>(object));
        } else if constexpr (std::is_same_v<std::decay_t<decltype(i)>, Pawn>){
            auto& object = std::get<Pawn>(i);
            Vector2 obj_pos = Vector2(object.GetPosition().x / this->world_block_size, object.GetPosition().y / this->world_block_size);
            // Check if the target block is available
            if (this->actor_block_map.find(obj_pos) == this->actor_block_map.end()){
                // Add the object to the block
                this->actor_block_map[obj_pos].emplace_back(std::vector<std::unique_ptr<T_ObjectInBlockWithoutUnique>>{std::make_unique<T_ObjectInBlockWithoutUnique>(object)});
                continue;
            }
            this->actor_block_map.at(obj_pos).emplace_back(std::make_unique<T_ObjectInBlockWithoutUnique>(object));
        } else if constexpr (std::is_same_v<std::decay_t<decltype(i)>, Character>){
            auto& object = std::get<Character>(i);
            Vector2 obj_pos = Vector2(object.GetPosition().x / this->world_block_size, object.GetPosition().y / this->world_block_size);
            // Check if the target block is available
            if (this->actor_block_map.find(obj_pos) == this->actor_block_map.end()){
                // Add the object to the block
                this->actor_block_map[obj_pos].emplace_back(std::vector<std::unique_ptr<T_ObjectInBlockWithoutUnique>>{std::make_unique<T_ObjectInBlockWithoutUnique>(object)});
                continue;
            }
            this->actor_block_map.at(obj_pos).emplace_back(std::make_unique<T_ObjectInBlockWithoutUnique>(object));
        }
    }
}

