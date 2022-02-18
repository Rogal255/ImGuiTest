#pragma once

#include <imgui.h>
#include "bindings/imgui_impl_glfw.h"
#include "bindings/imgui_impl_opengl3.h"

class UseImGui {
public:
    void Init(GLFWwindow* window, const char* glsl_version);
    virtual void Update();
    void Render();
    void Shutdown();
    bool pressed{false};

private:
    void NewFrame();
};
