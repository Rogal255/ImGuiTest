cmake_minimum_required(VERSION 3.21)
project(DearImGuiConan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


add_executable(DearImGuiConan main.cpp UseImGui.cpp bindings/imgui_impl_glfw.cpp bindings/imgui_impl_opengl3.cpp)
target_link_libraries(DearImGuiConan ${CONAN_LIBS})
include_directories(${CONAN_INCLUDE_DIRS_IMGUI} ${CONAN_INCLUDE_DIRS_GLFW} ${CONAN_INCLUDE_DIRS_GLEW})
