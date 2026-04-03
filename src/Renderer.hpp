#pragma once

#include <cstdint>

// Forward declarations
class VertexArray;
class IndexBuffer;
class Shader;

/**
 * @brief Renderer class for managing OpenGL draw calls
 *
 * The Renderer provides an abstraction layer for issuing draw commands
 * to the GPU, handling different drawing modes and rendering techniques.
 */
class Renderer
{
public:
	/**
	 * @brief Clear the current framebuffer
	 *
	 * Clears the color and depth buffers to prepare for the next frame.
	 */
	void Clear() const;

	/**
	 * @brief Draw indexed geometry
	 * @param va Vertex array containing vertex data
	 * @param ib Index buffer containing indices
	 * @param shader Shader program to use for rendering
	 */
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;

	/**
	 * @brief Draw non-indexed geometry
	 * @param va Vertex array containing vertex data
	 * @param shader Shader program to use for rendering
	 */
	void Draw(const VertexArray& va, const Shader& shader) const;

	/**
	 * @brief Draw multiple instances of indexed geometry
	 * @param va Vertex array containing vertex data
	 * @param ib Index buffer containing indices
	 * @param shader Shader program to use for rendering
	 * @param instanceCount Number of instances to draw
	 */
	void DrawInstance(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, uint32_t instanceCount) const;
};