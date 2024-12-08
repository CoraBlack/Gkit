#ifndef GKIT_H
#define GKIT_H

#include "GkitSetting.h"
// Asset
#include "Asset/Asset.h"
#include "Asset/Image.h"
#include "Asset/Sprite.h"

// Graphics
#include "Graphics/Window.h"
#include "Graphics/Camera.h"

// Game Object
#include "GameObject/Actor.h"

#ifdef __cplusplus
extern "C"{
#endif

namespace Gkit{
    // Gkit lib version
    const char* VERSION = "0.12";

    extern int Gkit_Init();
    extern void Delay(unsigned int ms);

}// namespace Gkit

#ifdef __cplusplus
}// extern C
#endif

#endif // GKIT_H