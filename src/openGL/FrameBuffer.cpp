#include "FrameBuffer.hpp"
#include "Texture.hpp"
#include "debug/debug.hpp"

#include <glad/gl.h>

#include <iostream>

gkit::graphic::opengl::buffer::FrameBuffer::FrameBuffer(int width, int height)
	: fb_width(width), fb_height(height)
{
	GLCall(glGenFramebuffers(1, &m_RendererID));
	GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID));
}

gkit::graphic::opengl::buffer::FrameBuffer::~FrameBuffer()
{
	if(m_RendererID != 0)
	{
		GLCall(glDeleteFramebuffers(1, &m_RendererID));
		m_RendererID = 0;
	}
}

void gkit::graphic::opengl::buffer::FrameBuffer::AttachColorTexture(const gkit::graphic::opengl::Texture& texture, int slot)
{
	Bind();
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + slot, GL_TEXTURE_2D, texture.GetRenderID(), 0);
	std::cout<<"attach texture"<<std::endl;
}

void gkit::graphic::opengl::buffer::FrameBuffer::DetachColorTexture(int slot)
{
	Bind();
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + slot, GL_TEXTURE_2D, 0, 0);
	std::cout<<"detach texture"<<std::endl;
}

void gkit::graphic::opengl::buffer::FrameBuffer::AttachDepthStencil(const RenderBuffer& rbo) {
	Bind();
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, 
		GL_RENDERBUFFER, rbo.GetRendererID());
}

void gkit::graphic::opengl::buffer::FrameBuffer::DetachDepthStencil() {
	Bind();
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
								GL_RENDERBUFFER, 0);
}

void gkit::graphic::opengl::buffer::FrameBuffer::Check()
{
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cout << "==================================================" << std::endl;
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
		std::cout << "==================================================" << std::endl;
	}
	else
	{
		std::cout << "FRAMEBUFFER:: Framebuffer is complete!" << std::endl;
	}
   this->Unbind();
}

void gkit::graphic::opengl::buffer::FrameBuffer::SetViewport(int x, int y, int width, int height)
{
	GLCall(glViewport(x, y, width, height));
}

void gkit::graphic::opengl::buffer::FrameBuffer::SetViewport(int width, int height)
{
	GLCall(glViewport(leftX, bottomY, width, height));
}

void gkit::graphic::opengl::buffer::FrameBuffer::SetViewport()
{
	GLCall(glViewport(leftX, bottomY, fb_width, fb_height));
}

void gkit::graphic::opengl::buffer::FrameBuffer::Bind() const
{
	GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID));
	GLCall(glEnable(GL_DEPTH_TEST));
	GLCall(glViewport(leftX, bottomY, fb_width, fb_height));
}

void gkit::graphic::opengl::buffer::FrameBuffer::Unbind() const
{
	GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
}