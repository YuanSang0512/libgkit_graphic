#include "VertexBuffer.hpp"
#include "debug/debug.hpp"

#include <glad/gl.h>

gkit::graphic::opengl::buffer::VertexBuffer::VertexBuffer(const void* data, uint32_t size, bool Dynamic)
{
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    if (!Dynamic){
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    }
    else {
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW));
    }
}

gkit::graphic::opengl::buffer::VertexBuffer::~VertexBuffer()
{
    if(m_RendererID != 0)
    {
        GLCall(glDeleteBuffers(1, &m_RendererID));
        m_RendererID = 0;
    }
}

auto gkit::graphic::opengl::buffer::VertexBuffer::Bind() const -> void
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

auto gkit::graphic::opengl::buffer::VertexBuffer::Unbind() const -> void
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
