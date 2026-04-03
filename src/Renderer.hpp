#pragma once

#include <cstdint>

class VertexArray;
class IndexBuffer;
class Shader;

class Renderer
{
public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void Draw(const VertexArray& va, const Shader& shader) const;
    void DrawInstance(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, uint32_t instanceCount) const;
};