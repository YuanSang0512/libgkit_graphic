cmake_minimum_required(VERSION 3.16)
project(libgkit_graphic LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置默认构建类型
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

# 添加 third_party cmake 模块路径
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/third_party/glad/cmake")

# 构建 third_party 依赖
add_subdirectory(third_party)

# 构建 GLAD OpenGL 库
# 使用 glad_add_library 自动生成 OpenGL 规范代码
# REPRODUCIBLE: 使用本地规范文件，不从远程下载
# LOCATION: 将生成的源码放到 build/glad 目录下
glad_add_library(glad_gl SHARED API "gl:core=4.6" REPRODUCIBLE
    LOCATION "${CMAKE_BINARY_DIR}/glad")

# 创建可执行目标示例 (可选)
# add_executable(${PROJECT_NAME} src/main.cpp)
# target_link_libraries(${PROJECT_NAME} PRIVATE glad_gl glfw)

# 测试目标
add_executable(test_app test/test.cpp)
target_include_directories(test_app PRIVATE
    ${CMAKE_SOURCE_DIR}/third_party/glm
    ${CMAKE_SOURCE_DIR}/third_party/glfw/include
    ${CMAKE_BINARY_DIR}/glad/include
)
target_link_libraries(test_app PRIVATE glad_gl glfw)