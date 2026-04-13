#pragma once

/**
 * @brief Render buffer wrapper for OpenGL renderbuffer objects
 *
 * A RenderBuffer is an off-screen buffer that stores rendered images but
 * cannot be directly sampled by shaders. Typically used for depth and
 * stencil attachments in a FrameBuffer.
 */
namespace gkit::graphic::opengl::buffer{

	class RenderBuffer
	{
	private:
		unsigned int m_RendererID;  ///< OpenGL renderbuffer ID
	public:
		/**
		* @brief Construct a renderbuffer
		*/
		RenderBuffer(int width, int height);

		/**
		* @brief Destructor - deletes the renderbuffer
		*/
		~RenderBuffer();

		/**
		* @brief Bind this renderbuffer to the current OpenGL context
		*/
		auto Bind() const -> void;

		/**
		* @brief Unbind this renderbuffer from the current OpenGL context
		*/
		auto Unbind() const -> void;

		auto GetRendererID() const -> int {return m_RendererID; }
	};

}