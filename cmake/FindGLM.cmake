# ============================================================================
# File location: /cmake/FindGLM.cmake
# Purpose: Find GLM library path and create IMPORTED target
# ============================================================================
find_path(GLM_INCLUDE_DIR
    NAMES glm/glm.hpp
    PATHS
        ${CMAKE_SOURCE_DIR}/test/extern/glm
        /usr/include
        /usr/local/include
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLM REQUIRED_VARS GLM_INCLUDE_DIR)

if(GLM_FOUND AND NOT TARGET glm::glm)
    add_library(glm::glm INTERFACE IMPORTED)
    set_target_properties(glm::glm PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${GLM_INCLUDE_DIR}
    )
endif()