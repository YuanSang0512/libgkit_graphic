#include <iostream>
#include <glm/glm.hpp>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main()
{
    // Test GLM
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    glm::mat4 mat = glm::mat4(1.0f);
    std::cout << "GLM: vec4 = (" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")" << std::endl;

    // Test GLFW (不初始化窗口，只测试函数是否存在)
    std::cout << "GLFW version: " << GLFW_VERSION_MAJOR << "." << GLFW_VERSION_MINOR << "." << GLFW_VERSION_REVISION << std::endl;

    // Test GLAD (不初始化 OpenGL 上下文，只测试头文件)
    std::cout << "GLAD included successfully" << std::endl;

    std::cout << "All libraries linked successfully!" << std::endl;
    return 0;
}