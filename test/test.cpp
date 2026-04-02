#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main()
{
    #pragma region init
    // 初始化 GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 配置 OpenGL 上下文 (Core Profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(1440, 720, "Test Window", nullptr, nullptr);

    // 设置当前上下文
    glfwMakeContextCurrent(window);

    // 初始化 GLAD (在设置上下文后调用)
    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    #pragma endregion

    // 渲染循环
    while (!glfwWindowShouldClose(window))
    {
        // 处理输入事件
        glfwPollEvents();

        // 渲染
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 交换缓冲区
        glfwSwapBuffers(window);
    }

    // 清理
    glfwTerminate();
    std::cout << "Window closed successfully" << std::endl;
    return 0;
}