# Third party dependencies

# GLAD - OpenGL Loader (需要在其他库之前加载，因为它提供了 glad_add_library 函数)
add_subdirectory(glad/cmake)

# GLFW
add_subdirectory(glfw)

# GLM - OpenGL Mathematics (header-only library)
# 只需要将 glm 目录加入 include 路径即可
# 在使用 glm 的 target 中添加: target_include_directories(target PRIVATE ${CMAKE_SOURCE_DIR}/third_party/glm)
# 或者在根 CMakeLists.txt 中全局设置:
# include_directories(${CMAKE_SOURCE_DIR}/third_party/glm)