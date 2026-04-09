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
		RenderBuffer();

		/**
		* @brief Destructor - deletes the renderbuffer
		*/
		~RenderBuffer();

		/**
		* @brief Check if the renderbuffer is properly configured
		*/
		void Check();

		/**
		* @brief Bind this renderbuffer to the current OpenGL context
		*/
		void Bind() const;

		/**
		* @brief Unbind this renderbuffer from the current OpenGL context
		*/
		void Unbind() const;
	};

}