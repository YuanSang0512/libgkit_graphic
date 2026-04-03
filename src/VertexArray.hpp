#pragma once

#include <cstdint>

// Forward declarations
class VertexBufferLayout;
class VertexBuffer;

/**
 * @brief Vertex array wrapper for OpenGL vertex array objects (VAO)
 *
 * A VertexArray stores the configuration of vertex attributes and their
 * associated buffers, binding them together for efficient rendering.
 */
class VertexArray
{
public:
	/**
	 * @brief Construct a vertex array object
	 */
	VertexArray();

	/**
	 * @brief Destructor - deletes the vertex array object
	 */
	~VertexArray();

	/**
	 * @brief Add a vertex buffer with a layout
	 * @param vb Vertex buffer to add
	 * @param layout Layout defining the vertex attributes
	 */
	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	/**
	 * @brief Add an instance buffer for instanced rendering
	 * @param vb Vertex buffer containing instance data
	 */
	void AddInstanceBuffer(const VertexBuffer& vb);

	/**
	 * @brief Bind this vertex array to the current OpenGL context
	 */
	void Bind() const;

	/**
	 * @brief Unbind this vertex array from the current OpenGL context
	 */
	void Unbind() const;

private:
	uint32_t m_RendererID;     		///< OpenGL vertex array ID
	uint32_t m_AttribIndex = 0;     ///< Current attribute index for adding new attributes
};