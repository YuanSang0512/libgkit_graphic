#pragma once

class VertexArray;
class IndexBuffer;
class Shader;

class Renderer
{
public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void Draw(const VertexArray& va, const Shader& shader) const;
    void DrawInstance(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, unsigned int instanceCount) const;
};