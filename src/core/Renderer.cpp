#include "openGL/VertexArray.hpp"
#include "openGL/IndexBuffer.hpp"
#include "openGL/StateManager.hpp"
#include "debug/debug.hpp"
#include "Renderer.hpp"
#include "Shader.hpp"

#include <glad/gl.h>

auto gkit::graphic::Renderer::Get() -> Renderer&
{
	static Renderer instance;
	return instance;
}

auto gkit::graphic::Renderer::GetStateManager() -> opengl::StateManager&
{
	return opengl::StateManager::Get();
}

auto gkit::graphic::Renderer::Clear(opengl::ClearFlags flags) const -> void
{
    GLbitfield mask = static_cast<GLbitfield>(flags);
    glClear(mask);
}

auto gkit::graphic::Renderer::Draw(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::opengl::buffer::IndexBuffer& ib, const gkit::graphic::Shader& shader) const -> void
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

auto gkit::graphic::Renderer::Draw(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::Shader& shader) const -> void
{
    shader.Bind();
    va.Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
}

auto gkit::graphic::Renderer::DrawInstance(const gkit::graphic::opengl::VertexArray& va, const gkit::graphic::opengl::buffer::IndexBuffer& ib, const gkit::graphic::Shader& shader, uint32_t instanceCount) const -> void
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElementsInstanced(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr, instanceCount));
}