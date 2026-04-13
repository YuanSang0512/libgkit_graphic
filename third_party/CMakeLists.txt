add_subdirectory(glad/cmake)

glad_add_library(glad_gl STATIC
    API "gl:core=4.6"
    REPRODUCIBLE
    LOCATION "${CMAKE_BINARY_DIR}/glad"
)

target_include_directories(glad_gl INTERFACE
    ${CMAKE_BINARY_DIR}/glad/include
)