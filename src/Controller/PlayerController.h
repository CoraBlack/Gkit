#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <SDL2/SDL.h>
#include <mutex>
#include <thread>
#include <functional>
#include <unordered_map>

namespace Gkit{
    typedef enum {
    // Alphabetic key in English keyboard
    KEY_A      = SDLK_a,
    KEY_B      = SDLK_b,
    KEY_C      = SDLK_c,
    KEY_D      = SDLK_d,
    KEY_E      = SDLK_e,
    KEY_F      = SDLK_f,
    KEY_G      = SDLK_g,
    KEY_H      = SDLK_h,
    KEY_I      = SDLK_i,
    KEY_J      = SDLK_j,
    KEY_K      = SDLK_k,
    KEY_L      = SDLK_l,
    KEY_M      = SDLK_m,
    KEY_N      = SDLK_n,
    KEY_O      = SDLK_o,
    KEY_P      = SDLK_p,
    KEY_Q      = SDLK_q,
    KEY_R      = SDLK_r,
    KEY_S      = SDLK_s,
    KEY_T      = SDLK_t,
    KEY_U      = SDLK_u,
    KEY_V      = SDLK_v,
    KEY_W      = SDLK_w,
    KEY_X      = SDLK_x,
    KEY_Y      = SDLK_y,
    KEY_Z      = SDLK_z,

    // Numeric key in English keyboard
    KEY_0      = SDLK_0,
    KEY_1      = SDLK_1,
    KEY_2      = SDLK_2,
    KEY_3      = SDLK_3,
    KEY_4      = SDLK_4,
    KEY_5      = SDLK_5,
    KEY_6      = SDLK_6,
    KEY_7      = SDLK_7,
    KEY_8      = SDLK_8,
    KEY_9      = SDLK_9,

    // Function key in English keyboard
    KEY_F1     = SDLK_F1,
    KEY_F2     = SDLK_F2,
    KEY_F3     = SDLK_F3,
    KEY_F4     = SDLK_F4,
    KEY_F5     = SDLK_F5,
    KEY_F6     = SDLK_F6,
    KEY_F7     = SDLK_F7,
    KEY_F8     = SDLK_F8,
    KEY_F9     = SDLK_F9,
    KEY_F10    = SDLK_F10,
    KEY_F11    = SDLK_F11,
    KEY_F12    = SDLK_F12,


    // Control key in English keyboard
    KEY_RETURN = SDLK_RETURN,
    KEY_ESCAPE = SDLK_ESCAPE,
    KEY_SPACE  = SDLK_SPACE,
    KEY_LEFT   = SDLK_LEFT,
    KEY_RIGHT  = SDLK_RIGHT,
    KEY_UP     = SDLK_UP,
    KEY_DOWN   = SDLK_DOWN,
    
} InputKey;

typedef enum {
    KEY_PRESS,
    KEY_UNPRESS
} KeyState;

struct KeyType{
    InputKey key;
    KeyState state;
    bool operator == (const KeyType& other) const;
};

} // namespace Gkit


// Specialized std:: Hash template
namespace std {
    template <>
    struct hash<Gkit::KeyType> {
        std::size_t operator()(const Gkit::KeyType& k) const {
            // Use the combined hash function to calculate the hash value of the KeyType
            std::size_t h1 = std::hash<Gkit::InputKey>{}(k.key);
            std::size_t h2 = std::hash<Gkit::KeyState>{}(k.state);
            return h1 ^ (h2 << 1); // Simple combined hash function
        }
    };
} // namespace std

namespace Gkit {

class PlayerController {
public:
    PlayerController() ;
    ~PlayerController();
    /**
     * @brief Set input callback function of a key
     * @since Version 0.12
     * @author Cora
     * @param key -- key code.InputKey type.
     * @param callback -- callback function.It must be a function with no parameters and no return value.
     * @return void
     */
    void SetInput(KeyType, std::function<void()> callback);
    /**
     * @brief Pause to input.
     * @since Version 0.12
     * @author Cora
     * @param  None
     * @return void
     */
    void PauseInput();

private:
    void        ListenKeyPress(float delta);
    InputKey    CastSDLKeyCodeToInputKey(SDL_KeyCode key) const;
    SDL_KeyCode CastInputKeyToSDLKeyCode(InputKey    key) const;

private:
    std::unordered_map<KeyType, std::function<void()>> input_map;
    bool        isLaunchKeyListen = true;
    std::mutex  input_switch       = std::mutex();
    std::thread input_listen_thread = std::thread();
};

} // namespace Gkit

#endif