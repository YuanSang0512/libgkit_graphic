#pragma once

#include <cstdlib>

// Platform-specific debug break macro
#ifdef _MSC_VER
    #define DEBUG_BREAK() __debugbreak()
#else
    #define DEBUG_BREAK() __builtin_trap()
#endif

/**
 * @brief Assertion macro that triggers a debug break if the condition is false
 * @param x Condition to evaluate
 */
#define ASSERT(x) if(!(x)) DEBUG_BREAK();

/**
 * @brief OpenGL error checking macro
 *
 * Clears any existing GL errors before executing the code, then checks
 * if any new errors occurred and logs them if so.
 * @param x OpenGL function call to wrap
 */
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

/**
 * @brief Clear all pending OpenGL errors
 *
 * Retrieves and discards all error flags from the OpenGL error queue.
 */
auto GLClearError() -> void;

/**
 * @brief Log an OpenGL function call and check for errors
 * @param function The function call as a string
 * @param file Source file where the call occurred
 * @param line Line number in the source file
 * @return true if no error occurred, false otherwise
 */
auto GLLogCall(const char* function, const char* file, int line) -> bool;