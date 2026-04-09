set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(extern/glfw EXCLUDE_FROM_ALL)

add_executable(test_app test.cpp)

target_include_directories(test_app PRIVATE
    ${CMAKE_BINARY_DIR}/glad/include
    ${CMAKE_SOURCE_DIR}/src
)

if(USE_EXTERNAL_GLM)
    target_include_directories(test_app PRIVATE
        ${CMAKE_SOURCE_DIR}/test/extern/glm/glm
    )
endif()

target_link_libraries(test_app PRIVATE
    libgkit_graphic
    glad_gl
    glfw
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/texture.shader
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/post_process.shader
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/container2.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test)

set_target_properties(test_app PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)