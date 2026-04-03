#pragma once

#include <cstdint>

class VertexBufferLayout;
class VertexBuffer;

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void AddInstanceBuffer(const VertexBuffer& vb);

	void Bind() const;
	void Unbind() const;
private:
	uint32_t m_RendererID;
	uint32_t m_AttribIndex = 0;
};