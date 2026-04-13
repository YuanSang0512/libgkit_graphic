file(GLOB_RECURSE LIBGKIT_SOURCES CONFIGURE_DEPENDS "*.cpp")

# 添加 stb_image 源文件
list(APPEND LIBGKIT_SOURCES
    ${CMAKE_SOURCE_DIR}/test/extern/stb_image/stb_image.cpp
)

add_library(libgkit_graphic STATIC ${LIBGKIT_SOURCES})

target_include_directories(libgkit_graphic
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE
        ${CMAKE_BINARY_DIR}/glad/include
)

if(USE_EXTERNAL_GLM)
    target_include_directories(libgkit_graphic PUBLIC
        ${CMAKE_SOURCE_DIR}/test/extern/glm
        ${CMAKE_SOURCE_DIR}/test/extern/stb_image
    )
    target_compile_definitions(libgkit_graphic PUBLIC GKIT_USE_GLM)
    message(STATUS "Using external GLM (temporary)")
endif()

target_link_libraries(libgkit_graphic PRIVATE glad_gl)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_command(TARGET libgkit_graphic POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_SOURCE_DIR}/compile_commands.json
        COMMENT "Copying compile_commands.json"
    )
endif()