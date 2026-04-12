#include "FrameBuffer.hpp"
#include "config.hpp"
#include "debug/debug.hpp"

#include <glad/gl.h>

#include <iostream>

gkit::graphic::opengl::buffer::FrameBuffer::FrameBuffer()
{
	GLCall(glGenFramebuffers(1, &m_RendererID));
	GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID));
}

gkit::graphic::opengl::buffer::FrameBuffer::~FrameBuffer()
{
	GLCall(glDeleteFramebuffers(1, &m_RendererID));
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

void gkit::graphic::opengl::buffer::FrameBuffer::Bind() const
{
	GLCall(glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID));
	GLCall(glEnable(GL_DEPTH_TEST));
	GLCall(glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT));
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void gkit::graphic::opengl::buffer::FrameBuffer::Unbind() const
{
	GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
	GLCall(glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT));

}