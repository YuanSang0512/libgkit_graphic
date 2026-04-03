#pragma once
#include "debug.hpp"

#include <vector>
#include <glad/gl.h>
#include <glm/glm.hpp>

#include <cstdint>

struct VertexBufferElement
{
	uint32_t type;
	uint32_t count;
	unsigned char normalized;

	static uint32_t GetSizeOfType(uint32_t type)
	{
		switch (type)
		{
		case GL_FLOAT: return 4;
		case GL_UNSIGNED_INT: return 4;
		case GL_UNSIGNED_BYTE: return 1;
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	uint32_t m_Stride;
public:
	VertexBufferLayout() : m_Stride(0) {}

	template<typename T>
	void Push(uint32_t count)
	{
		static_assert(sizeof(T) == 0, "Unsupported type for VertexBufferLayout::Push");
	}

	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
	inline uint32_t GetStride() const { return m_Stride; }
};

// Template specialization outside the class
template<>
inline void VertexBufferLayout::Push<float>(uint32_t count)
{
	m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
	m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
}

template<>
inline void VertexBufferLayout::Push<uint32_t>(uint32_t count)
{
	m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
	m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
}

template<>
inline void VertexBufferLayout::Push<unsigned char>(uint32_t count)
{
	m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
	m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
}