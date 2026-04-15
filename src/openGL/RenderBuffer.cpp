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

auto gkit::graphic::opengl::buffer::RenderBuffer::Bind() const -> void
{
	GLCall(glBindRenderbuffer(GL_RENDERBUFFER, m_RendererID));
}
auto gkit::graphic::opengl::buffer::RenderBuffer::Unbind() const -> void
{
	GLCall(glBindRenderbuffer(GL_RENDERBUFFER, 0));
}