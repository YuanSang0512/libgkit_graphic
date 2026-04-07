#include "Renderer.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "debug.hpp"
#include <glad/gl.h>

void gkit::graphic::Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void gkit::graphic::Renderer::Draw(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::opengl::buffer::IndexBuffer& ib, const gkit::graphic::Shader& shader) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void gkit::graphic::Renderer::Draw(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::Shader& shader) const
{
    shader.Bind();
    va.Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
}

void gkit::graphic::Renderer::DrawInstance(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::opengl::buffer::IndexBuffer& ib, const gkit::graphic::Shader& shader, uint32_t instanceCount) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElementsInstanced(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr, instanceCount));
}