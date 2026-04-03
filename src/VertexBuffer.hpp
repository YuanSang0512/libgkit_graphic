#pragma once

#include <cstdint>

class VertexBuffer
{
private:
	uint32_t m_RendererID;
public:
	VertexBuffer(const void* data, uint32_t size, bool Dynamic = false);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};