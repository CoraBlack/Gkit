#ifndef GKIT_H
#define GKIT_H

#include "GkitSetting.h"
// Asset
#include "Asset/Asset.h"
#include "Asset/Image.h"

// Controller
#include "Controller/PlayerController.h"

// Graphics
#include "Graphics/Window.h"
#include "Graphics/Camera.h"

// Scene
#include "Scene/World/World.h"
#include "Scene/World/WorldMode.h"
#include "Scene/Scenario/Scenario.h"

// Sprite
#include "Sprite/Sprite.h"

// Game Object
#include "GameObject/Actor.h"
#include "GameObject/Pawn.h"
#include "GameObject/Character.h"

// Global type
#include "Vector2.h"

#ifdef __cplusplus
extern "C"{
#endif

namespace Gkit{
    // Gkit lib version
    const char* VERSION = "0.20";

    extern int Gkit_Init();
    extern void Delay(unsigned int ms);

}// namespace Gkit

#ifdef __cplusplus
}// extern C
#endif

#endif // GKIT_H