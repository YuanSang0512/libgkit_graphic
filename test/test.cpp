#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "src/VertexArray.hpp"
#include "src/VertexBuffer.hpp"
#include "src/IndexBuffer.hpp"
#include "src/VertexBufferLayout.hpp"
#include "src/Shader.hpp"
#include "src/Renderer.hpp"

int main()
{
    #pragma region init
    // init GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // config OpenGL context (Core Profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // build window
    GLFWwindow* window = glfwCreateWindow(1440, 720, "Test Window", nullptr, nullptr);

    // setup current context
    glfwMakeContextCurrent(window);

    // init GLAD
    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    #pragma endregion

    #pragma region triangle
    // vertex data
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // index data
    unsigned int indices[] = {
        0, 1, 2
    };

    {
        // create vertex buffer
        VertexBuffer vb(vertices, sizeof(vertices));

        // create index buffer
        IndexBuffer ib(indices, 3);

        // create vertex array
        VertexArray va;

        // setup buffer layout (3个 float 组成 position)
        VertexBufferLayout layout;
        layout.Push<float>(3);
        va.AddBuffer(vb, layout);

        // load shader source
        Shader shader("test/basic.shader");
        #pragma endregion

        #pragma region render
        // create renderer
        Renderer renderer;

        // render cycle
        while (!glfwWindowShouldClose(window))
        {
            // process input event
            glfwPollEvents();

            // ESC
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);

            // render core
            renderer.Clear();
            shader.Bind();
            renderer.Draw(va, ib, shader);

            // swap buffer
            glfwSwapBuffers(window);
        }
        #pragma endregion
    }
    // clear
    glfwTerminate();
    std::cout << "Window closed successfully" << std::endl;
    return 0;
}