# ============================================================================
# 文件位置: /cmake/FindGLM.cmake
# 职责: 查找GLM库的路径，创建IMPORTED目标
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