#include "Renderer.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "debug.hpp"
#include <glad/gl.h>

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Draw(const VertexArray& va, const Shader& shader) const
{
    shader.Bind();
    va.Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
}

/// <summary>
/// 实例化绘制
/// </summary>
/// <param name="va"></param>
/// <param name="ib"></param>
/// <param name="shader"></param>
/// <param name="instanceCount">绘制数量</param>
void Renderer::DrawInstance(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, unsigned int instanceCount) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElementsInstanced(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr, instanceCount));
}