#include "Gkit.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_ttf.h>

/**
 * Gkit Gkit_Init
 * @author Cora
 * @since Version 0.11
 * @param None
 * @return void
 * 
 * Init Gkit something is essential.
 * Such as the subsystems of SDL2.
 * 
 * You must call this function when you start to create a game.
 * 
 * Forever!
 */
int Gkit::Gkit_Init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    return 0;
}

/**
 * Gkit Delay
 * @author Cora
 * @since Version 0.12
 * @param ms --unsigned int, the delay time(ms)
 * @return void
 * 
 * Make the program delay to work for a while
 */
inline void Gkit::Delay(unsigned int ms){
    SDL_Delay(ms);
}