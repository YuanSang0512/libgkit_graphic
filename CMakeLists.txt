cmake_minimum_required(VERSION 3.16)
project(libgkit_graphic LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands for IDEs and tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

# add third_party cmake module path
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/third_party/glad/cmake")

# build third_party
add_subdirectory(third_party)

# build GLAD OpenGL lib
# use glad_add_library auto build (path:./build/glad)
glad_add_library(glad_gl SHARED API "gl:core=4.6" REPRODUCIBLE
    LOCATION "${CMAKE_BINARY_DIR}/glad")

# create library target
add_library(libgkit_graphic STATIC
    src/Renderer.cpp
    src/IndexBuffer.cpp
    src/VertexBuffer.cpp
    src/VertexArray.cpp
    src/Shader.cpp
    src/debug.cpp
)
target_include_directories(libgkit_graphic PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/glad/include
)
target_link_libraries(libgkit_graphic PRIVATE glad_gl glfw)

# test target
add_executable(test_app test/test.cpp)
target_include_directories(test_app PRIVATE
    ${CMAKE_BINARY_DIR}/glad/include
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(test_app PRIVATE libgkit_graphic glad_gl glfw)

# Create symlink to compile_commands.json in source directory
if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_command(TARGET libgkit_graphic POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_SOURCE_DIR}/compile_commands.json
        COMMENT "Creating symlink to compile_commands.json"
    )
endif()
