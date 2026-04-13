#pragma once

#include "openGL/Texture.hpp"
#include "RenderBuffer.hpp"

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
		unsigned int fb_height, fb_width;	///< frameBuffer size
		unsigned int leftX = 0, bottomY = 0;	///< left bottom coordinate of frameBuffer
	public:
		/**
		* @brief Construct a framebuffer
		*/
		FrameBuffer(int width, int height);

		/**
		* @brief Destructor - deletes the framebuffer
		*/
		~FrameBuffer();

		/**
		 * @brief Attach a color texture to this framebuffer
		 * @param texture The texture to attach as color attachment
		 * @param slot Attachment slot (typically 0 for GL_COLOR_ATTACHMENT0)
		 */
		void AttachColorTexture(const gkit::graphic::opengl::Texture& texture, int slot = 0);

		/**
		 * @brief Detach a color texture from this framebuffer
		 * @param slot Attachment slot to detach
		 */
		void DetachColorTexture(int slot = 0);

			/**
		 * @brief Attach a depth-stencil renderbuffer to this framebuffer
		 * @param rbo The renderbuffer to attach as depth-stencil attachment
		 */
		void AttachDepthStencil(const gkit::graphic::opengl::buffer::RenderBuffer& rbo);

		/**
		 * @brief Detach the depth-stencil attachment from this framebuffer
		 */
		void DetachDepthStencil();
		
		/**
		* @brief Check if the framebuffer is complete
		*
		* Verifies that the framebuffer is properly configured and ready for rendering.
		* Prints status message to console.
		*/
		void Check();

		/**
		 * @brief Set viewport to the framebuffer's default size
		 *
		 * Uses the stored framebuffer dimensions (fb_width, fb_height).
		 */
		void SetViewport();

		/**
		 * @brief Set viewport to custom dimensions
		 * @param width Viewport width
		 * @param height Viewport height
		 */
		void SetViewport(int width, int height);

		/**
		 * @brief Set custom viewport with offset
		 * @param x Left coordinate
		 * @param y Bottom coordinate
		 * @param width Viewport width
		 * @param height Viewport height
		 */
		void SetViewport(int x, int y, int width, int height);

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