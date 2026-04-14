#include "openGL/VertexArray.hpp"
#include "openGL/VertexBuffer.hpp"
#include "openGL/IndexBuffer.hpp"
#include "openGL/VertexBufferLayout.hpp"
#include "openGl/RenderBuffer.hpp"
#include "openGL/FrameBuffer.hpp"
#include "openGL/Texture.hpp"
#include "openGL/config.hpp"

#include "core/Shader.hpp"
#include "core/Renderer.hpp"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // build window
    GLFWwindow* window = glfwCreateWindow(gkit::graphic::opengl::SCR_WIDTH, gkit::graphic::opengl::SCR_HEIGHT, "Test Window", nullptr, nullptr);

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
    // Triangle vertex data
    float picVertices[] = {
        // positions        // tex coords
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
        0.5f,  0.5f, 0.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f
    };

    // index data
    unsigned int picIndices[] = { 0, 1, 2, 2, 3, 0 };

    {
        gkit::graphic::opengl::VertexArray picVAO;
        gkit::graphic::opengl::buffer::VertexBuffer picVBO(picVertices, sizeof(picVertices));
        gkit::graphic::opengl::buffer::IndexBuffer picIBO(picIndices, 6);

        gkit::graphic::opengl::buffer::VertexBufferLayout picLayout;
        picLayout.Push<float>(3);
        picLayout.Push<float>(2);
        picVAO.AddBuffer(picVBO, picLayout);

        // load shader source
        gkit::graphic::Shader picShader("test/texture.shader");
        gkit::graphic::opengl::Texture mainTexture("test/container2.png", gkit::graphic::opengl::TextureType::TEXTURE_2D);

        #pragma endregion

        #pragma region quad
        // Full-screen quad vertex data (post-processing)
        float quadVertices[] = {
            // positions                    // tex coords
            -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,
            1.0f, -1.0f, 0.0f,  1.0f, 0.0f,
            1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
            -1.0f,  1.0f, 0.0f,  0.0f, 1.0f
        };

        unsigned int quadIndices[] = { 0, 1, 2, 2, 3, 0 };

        gkit::graphic::opengl::VertexArray quadVAO;
        gkit::graphic::opengl::buffer::VertexBuffer quadVB(quadVertices, sizeof(quadVertices));
        gkit::graphic::opengl::buffer::IndexBuffer quadIB(quadIndices, 6);

        gkit::graphic::opengl::buffer::VertexBufferLayout quadLayout;
        quadLayout.Push<float>(3);
        quadLayout.Push<float>(2);
        quadVAO.AddBuffer(quadVB, quadLayout);

        // load post-processing shader
        gkit::graphic::Shader postShader("test/post_process.shader");
        #pragma endregion

        #pragma region framebuffer
        gkit::graphic::opengl::buffer::FrameBuffer fbo(gkit::graphic::opengl::SCR_WIDTH, gkit::graphic::opengl::SCR_HEIGHT);
        gkit::graphic::opengl::Texture fboTexture(" ", gkit::graphic::opengl::TextureType::TEXTURE_FRAMEBUFFER);
        gkit::graphic::opengl::buffer::RenderBuffer rbo(gkit::graphic::opengl::SCR_WIDTH, gkit::graphic::opengl::SCR_HEIGHT);
        fbo.AttachColorTexture(fboTexture, 0);
        fbo.AttachDepthStencil(rbo);
        fbo.Check();
        #pragma endregion

        #pragma region render
        auto& renderer = gkit::graphic::Renderer::Get();
        auto& stateManager = renderer.GetStateManager();
        
        int screenWidth = gkit::graphic::opengl::SCR_WIDTH;
        int screenHeight = gkit::graphic::opengl::SCR_HEIGHT;
        glDisable(GL_DEPTH_TEST);
        // render cycle
        while (!glfwWindowShouldClose(window))
        {
            // process input event
            glfwPollEvents();

            // ESC
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);

            fbo.Bind();
            fbo.SetViewport(0, 0, screenWidth, screenHeight);
            renderer.Clear(gkit::graphic::opengl::ClearFlags::All);
            // 1. Render to framebuffer
            picShader.Bind();
            mainTexture.Bind(0);
            renderer.Draw(picVAO, picIBO, picShader);

            // 2. Render to screen (post-processing)
            fbo.Unbind();
            renderer.Clear(gkit::graphic::opengl::ClearFlags::All);
            gkit::graphic::opengl::window::SetViewport(0, 0, screenWidth/2, screenHeight/2);
            stateManager.SetStencilTest(true);
            stateManager.SetStencil(gkit::graphic::opengl::CompareFunc::Always, 1, 0xFF);
            stateManager.SetStencilOp(
                 gkit::graphic::opengl::StencilOp::Keep, 
                gkit::graphic::opengl::StencilOp::Keep, 
                gkit::graphic::opengl::StencilOp::Replace);
            stateManager.Apply();
            picShader.Bind();
            mainTexture.Bind(0);
            renderer.Draw(picVAO, picIBO, picShader);

            gkit::graphic::opengl::window::SetViewport(0, 0, screenWidth, screenHeight);
            stateManager.SetStencil(gkit::graphic::opengl::CompareFunc::Equal, 1, 0xFF);
            stateManager.SetStencilOp(
                 gkit::graphic::opengl::StencilOp::Keep, 
                gkit::graphic::opengl::StencilOp::Keep, 
                gkit::graphic::opengl::StencilOp::Keep);
            stateManager.Apply();
            postShader.Bind();
            fboTexture.Bind(0);
            postShader.SetUniform1i("screenTexture", 0);
            renderer.Draw(quadVAO, quadIB, postShader);
            
            gkit::graphic::opengl::window::SetViewport(0, 0, screenWidth/4, screenHeight/4);
            postShader.Bind();
            fboTexture.Bind(0);
            postShader.SetUniform1i("screenTexture", 0);
            renderer.Draw(quadVAO, quadIB, postShader);
            
            stateManager.SetStencilTest(false);
            stateManager.Apply();
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