#include "RenderBuffer.hpp"
#include "debug/debug.hpp"

#include <glad/gl.h>

gkit::graphic::opengl::buffer::RenderBuffer::RenderBuffer(int width, int height)
{
	GLCall(glGenRenderbuffers(1, &m_RendererID));
	GLCall(glBindRenderbuffer(GL_RENDERBUFFER, m_RendererID));
	GLCall(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height));
	Unbind();
}

gkit::graphic::opengl::buffer::RenderBuffer::~RenderBuffer()
{
	if(m_RendererID != 0)
	{
		GLCall(glDeleteRenderbuffers(1, &m_RendererID));
		m_RendererID = 0;
	}
}

void gkit::graphic::opengl::buffer::RenderBuffer::Bind() const
{
	GLCall(glBindRenderbuffer(GL_RENDERBUFFER, m_RendererID));
}
void gkit::graphic::opengl::buffer::RenderBuffer::Unbind() const
{
	GLCall(glBindRenderbuffer(GL_RENDERBUFFER, 0));
}