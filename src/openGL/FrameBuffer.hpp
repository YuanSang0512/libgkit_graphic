#pragma once

/**
 * @brief Frame buffer wrapper for OpenGL framebuffer objects (FBO)
 *
 * A FrameBuffer is an off-screen rendering target that allows rendering
 * to a texture instead of the screen. Commonly used for post-processing
 * effects like color inversion, blur, bloom, etc.
 */
namespace gkit::graphic::opengl::buffer{

	class FrameBuffer
	{
	private:
		unsigned int m_RendererID;  ///< OpenGL framebuffer ID
	public:
		/**
		* @brief Construct a framebuffer
		*/
		FrameBuffer();

		/**
		* @brief Destructor - deletes the framebuffer
		*/
		~FrameBuffer();

		/**
		* @brief Check if the framebuffer is complete
		*
		* Verifies that the framebuffer is properly configured and ready for rendering.
		* Prints status message to console.
		*/
		void Check();

		/**
		* @brief Bind this framebuffer as the rendering target
		*/
		void Bind() const;

		/**
		* @brief Unbind this framebuffer, revert to default framebuffer (screen)
		*/
		void Unbind() const;
	};

}