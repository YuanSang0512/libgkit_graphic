#include "debug.hpp"

#include <glad/gl.h>

#include <iostream>

auto GLClearError() -> void
{
    while (glGetError() != GL_NO_ERROR);
}

auto GLLogCall(const char* function, const char* file, int line) -> bool
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << function << " in " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}