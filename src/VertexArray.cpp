#include "debug.hpp"

#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "Renderer.hpp"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererID))
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	size_t offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		//Specify the reading rules for the incoming data, the meaning of the arrays (coordinates, textures, etc.)
		GLCall(glVertexAttribPointer(m_AttribIndex, element.count, element.type,
			element.normalized, layout.GetStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
		m_AttribIndex++;
	}

}

void VertexArray::AddInstanceBuffer(const VertexBuffer& vb)
{
    Bind();
	vb.Bind();

    size_t vec4Size = sizeof(glm::vec4);

    for (uint32_t i = 0; i < 4; i++)
    {
        glEnableVertexAttribArray(m_AttribIndex);
        glVertexAttribPointer(
			m_AttribIndex,
            4,
            GL_FLOAT,
            GL_FALSE,
            sizeof(glm::mat4),
            (void*)(i * vec4Size)
        );
        glVertexAttribDivisor(m_AttribIndex, 1);
		m_AttribIndex++;
    }
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}