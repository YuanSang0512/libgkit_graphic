#include <glad/gl.h>

#include "debug/debug.hpp"
#include "IndexBuffer.hpp"

gkit::graphic::opengl::buffer::IndexBuffer::IndexBuffer(const uint32_t* data, uint32_t count)
    : m_Count(count)
{
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW));
}
gkit::graphic::opengl::buffer::IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void gkit::graphic::opengl::buffer::IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void gkit::graphic::opengl::buffer::IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}