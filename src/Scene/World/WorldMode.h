#ifndef WORLDMODE_H
#define WORLDMODE_H

#include <memory>

#include "../../GameObject/Pawn.h"
#include "../../Graphics/Window.h"
#include "../../Graphics/Camera.h"

namespace Gkit{

class WorldMode{
public:
    WorldMode(std::shared_ptr<Window> main_window, std::shared_ptr<Pawn> control_object, std::shared_ptr<Camera> main_camera);
    ~WorldMode();

    // Setters
    void SetControlObject(std::shared_ptr<Pawn> control_object);
    void SetMainCamera   (std::shared_ptr<Camera>  main_camera);
    void SetMainWindow   (std::shared_ptr<Window>  main_window);

    // Getters
    std::shared_ptr<Pawn> GetControlObject() const;
    std::shared_ptr<Camera>  GetMainCamera() const;
    std::shared_ptr<Window>  GetMainWindow() const;
private:
    std::shared_ptr<Pawn>    main_control_object;
    std::shared_ptr<Camera>  main_camera;
    std::shared_ptr<Window>  main_window;
}; // class WorldMode
}// namespace Gkit

#endif // WORLDMODE_H