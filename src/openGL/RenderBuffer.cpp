#include "RenderBuffer.hpp"
#include "debug/debug.hpp"
#include "config.hpp"

#include <glad/gl.h>

gkit::graphic::opengl::buffer::RenderBuffer::RenderBuffer()
{
	GLCall(glGenRenderbuffers(1, &m_RendererID));
	glBindRenderbuffer(GL_RENDERBUFFER, m_RendererID);
	GLCall(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCR_WIDTH, SCR_HEIGHT));
	GLCall(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RendererID));
}

gkit::graphic::opengl::buffer::RenderBuffer::~RenderBuffer()
{
	GLCall(glDeleteRenderbuffers(1, &m_RendererID));
}

void gkit::graphic::opengl::buffer::RenderBuffer::Bind() const
{
	GLCall(glBindRenderbuffer(GL_RENDERBUFFER, m_RendererID));
}
void gkit::graphic::opengl::buffer::RenderBuffer::Unbind() const
{
	GLCall(glBindRenderbuffer(GL_RENDERBUFFER, 0));
}