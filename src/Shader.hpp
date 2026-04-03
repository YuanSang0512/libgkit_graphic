#pragma once

#include <string>
#include <unordered_map>
#include <glad/gl.h>
#include <glm/glm.hpp>

#include <cstdint>

struct ShaderProgramSource {
	std::string vertexShader;
	std::string fragmenShader;
};

class Shader
{
private:
	uint32_t m_RendererID;
	std::string m_FilePath;
	std::unordered_map<std::string, int> m_UniformLocationCach;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	//set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);
	void SetUniformVec4f(const std::string& name, const glm::vec4& vector4);
	void SetUniformVec3f(const std::string& name, const glm::vec3& vector3);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
	void SetUniformMat3f(const std::string& name, const glm::mat3& matrix);
	void SetUniform1iv(const std::string& name, const int sz, const int* ind);
private:
	ShaderProgramSource ParseShader(const std::string& filePath);
	uint32_t CompileShader(uint32_t type, const std::string& source);
	uint32_t CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int GetUniformLocation(const std::string& name);

};