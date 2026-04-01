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

    // Test GLFW
    std::cout << "GLFW version: " << GLFW_VERSION_MAJOR << "." << GLFW_VERSION_MINOR << "." << GLFW_VERSION_REVISION << std::endl;

    // Test GLAD
    std::cout << "GLAD included successfully" << std::endl;

    std::cout << "All libraries linked successfully!" << std::endl;
    return 0;
}
