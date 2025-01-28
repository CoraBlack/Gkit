#include "WorldMode.h"

/// Constructor and Destructor ///
Gkit::WorldMode::WorldMode(std::shared_ptr<Window> main_window, std::shared_ptr<Pawn> control_object, std::shared_ptr<Camera> main_camera) 
    : main_control_object(control_object), main_camera(main_camera), main_window(main_window) {
    return;
}

Gkit::WorldMode::~WorldMode(){
    return;
}

/// Setters ///
void Gkit::WorldMode::SetControlObject(std::shared_ptr<Pawn> control_object){
    this->main_control_object = control_object;
}

void Gkit::WorldMode::SetMainCamera(std::shared_ptr<Camera> main_camera){
    this->main_camera = main_camera;
}

void Gkit::WorldMode::SetMainWindow(std::shared_ptr<Window> main_window){
    this->main_window = main_window;
}
/// Getters ///
std::shared_ptr<Gkit::Pawn> Gkit::WorldMode::GetControlObject() const{
    return main_control_object;
}

std::shared_ptr<Gkit::Camera> Gkit::WorldMode::GetMainCamera() const{
    return main_camera;
}

std::shared_ptr<Gkit::Window> Gkit::WorldMode::GetMainWindow() const{
    return main_window;
}