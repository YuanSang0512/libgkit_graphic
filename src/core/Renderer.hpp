#pragma once

#include "openGL/IndexBuffer.hpp"
#include "openGL/VertexArray.hpp"
#include "core/Shader.hpp"

#include <cstdint>

/**
 * @brief Renderer class providing public rendering interface
 *
 * The Renderer provides a unified interface for rendering operations.
 * Currently only OpenGL implementation is available, but the design allows
 * for future integration with other rendering backends (e.g., Vulkan).
 */
namespace gkit::graphic {

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
		void Draw(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::opengl::buffer::IndexBuffer& ib, const gkit::graphic::Shader& shader) const;

		/**
		* @brief Draw non-indexed geometry
		* @param va Vertex array containing vertex data
		* @param shader Shader program to use for rendering
		*/
		void Draw(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::Shader& shader) const;

		/**
		* @brief Draw multiple instances of indexed geometry
		* @param va Vertex array containing vertex data
		* @param ib Index buffer containing indices
		* @param shader Shader program to use for rendering
		* @param instanceCount Number of instances to draw
		*/
		void DrawInstance(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::opengl::buffer::IndexBuffer& ib, const gkit::graphic::Shader& shader, uint32_t instanceCount) const;
	};

} // namespace gkit::graphic