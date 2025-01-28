#include "PlayerController.h"

bool Gkit::KeyType::operator == (const Gkit::KeyType& key) const {
    return (this->key == key.key && this->state == key.state);
}

/// Tectonic deconstruction ///
Gkit::PlayerController::PlayerController(){
    this->input_listen_thread = std::thread(&Gkit::PlayerController::ListenKeyPress, this, 0.0f);
    this->input_listen_thread.detach();
}

Gkit::PlayerController::~PlayerController(){
    this->isLaunchKeyListen = false;
}

/// Input control ////
void Gkit::PlayerController::SetInput(KeyType key, std::function<void()> callback){
    // Check if key is already in map
    if (this->input_map.find(key) == this->input_map.end()){
        this->input_map.insert(std::make_pair(key, callback));
    }
    this->input_map.at(key) = callback;
}

void Gkit::PlayerController::PauseInput(){
    
}

void Gkit::PlayerController::ListenKeyPress(float delta){
    SDL_Event e;
    while (this->isLaunchKeyListen){
        if (this->input_switch.try_lock()){
            this->input_switch.unlock();
        }
        // Poll event
        if (SDL_PollEvent(&e)) {
            switch(e.type){
            case SDL_KEYDOWN:
                this->input_map.at(Gkit::KeyType{CastSDLKeyCodeToInputKey(static_cast<SDL_KeyCode>(e.key.keysym.sym)), Gkit::KEY_UNPRESS})();
                break;
            case SDL_KEYUP:
                this->input_map.at(Gkit::KeyType{CastSDLKeyCodeToInputKey(static_cast<SDL_KeyCode>(e.key.keysym.sym)), Gkit::KEY_PRESS})();
                break;
            }
        }
    }
}

/// SDL_KeyCode and Gkit:: Mutual conversion of InputKeys ///
inline Gkit::InputKey Gkit::PlayerController::CastSDLKeyCodeToInputKey(SDL_KeyCode key) const{
    return static_cast<Gkit::InputKey>(key);
}
inline SDL_KeyCode Gkit::PlayerController::CastInputKeyToSDLKeyCode(Gkit::InputKey key) const{
    return static_cast<SDL_KeyCode>(key);
}