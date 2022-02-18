#include "UseImGui.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "bindings/imgui_impl_glfw.h"
#include "bindings/imgui_impl_opengl3.h"
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cout << "glfw error'\n";
        return 1;
    }
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui - Conan", NULL, NULL);
    if (window == NULL) {
        std::cout << "Window error\n";
        return 1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (glewInit() != GLEW_OK) { return 1; }
    int screen_width, screen_height;
    glfwGetFramebufferSize(window, &screen_width, &screen_height);
    glViewport(0, 0, screen_width, screen_height);

    UseImGui myimgui;
    myimgui.Init(window, glsl_version);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        myimgui.Update();
        myimgui.Render();
        glfwSwapBuffers(window);
    }
    myimgui.Shutdown();
    return 0;
}
