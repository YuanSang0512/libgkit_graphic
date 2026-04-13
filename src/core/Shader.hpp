#pragma once

#include <string>
#include <unordered_map>
#include <cstdint>

namespace gkit::graphic{
	/**
	* @brief Structure holding parsed shader source code
	*/
	struct ShaderProgramSource {
		std::string vertexShader;    ///< Vertex shader source code
		std::string fragmenShader;   ///< Fragment shader source code (note: typo in original)
	};

	/**
	* @brief Shader wrapper for OpenGL shader programs
	*
	* Provides functionality to load, compile, and manage shader programs
	* including uniform variable manipulation.
	*/
	class Shader
	{
	private:
		uint32_t m_RendererID;                                  ///< OpenGL shader program ID
		std::string m_FilePath;                                   ///< Path to the shader file
		std::unordered_map<std::string, int> m_UniformLocationCach; ///< Cache for uniform locations
	public:
		/**
		* @brief Construct a shader from a file
		* @param filepath Path to the shader source file
		*/
		Shader(const std::string& filepath);

		/**
		* @brief Destructor - deletes the shader program
		*/
		~Shader();

		/**
		* @brief Bind this shader program to the current OpenGL context
		*/
		void Bind() const;

		/**
		* @brief Unbind this shader program from the current OpenGL context
		*/
		void Unbind() const;

		// Uniform setters

		/**
		* @brief Set an integer uniform variable
		* @param name Name of the uniform
		* @param value Integer value to set
		*/
		void SetUniform1i(const std::string& name, int value);

		/**
		* @brief Set a float uniform variable
		* @param name Name of the uniform
		* @param value Float value to set
		*/
		void SetUniform1f(const std::string& name, float value);

		/**
		* @brief Set a 4-component float uniform variable
		* @param name Name of the uniform
		* @param v0 First component
		* @param v1 Second component
		* @param f2 Third component
		* @param f3 Fourth component
		*/
		void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);

		/**
		* @brief Set a 4-component float vector uniform
		* @param name Name of the uniform
		* @param vector4 Pointer to 4-component float array
		*/
		void SetUniformVec4f(const std::string& name, const float* vector4);

		/**
		* @brief Set a 3-component float vector uniform
		* @param name Name of the uniform
		* @param vector3 Pointer to 3-component float array
		*/
		void SetUniformVec3f(const std::string& name, const float* vector3);

		/**
		* @brief Set a 4x4 float matrix uniform
		* @param name Name of the uniform
		* @param matrix Pointer to 16-element float array (column-major)
		*/
		void SetUniformMat4f(const std::string& name, const float* matrix);

		/**
		* @brief Set a 3x3 float matrix uniform
		* @param name Name of the uniform
		* @param matrix Pointer to 9-element float array (column-major)
		*/
		void SetUniformMat3f(const std::string& name, const float* matrix);

		/**
		* @brief Set an array of integer uniform variables
		* @param name Name of the uniform
		* @param sz Number of elements
		* @param ind Array of integer values
		*/
		void SetUniform1iv(const std::string& name, const int sz, const int* ind);

	private:
		/**
		* @brief Parse shader source from file
		* @param filePath Path to the shader file
		* @return Parsed shader source structure
		*/
		ShaderProgramSource ParseShader(const std::string& filePath);

		/**
		* @brief Compile a shader of the specified type
		* @param type Shader type (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER)
		* @param source Shader source code
		* @return Compiled shader ID
		*/
		uint32_t CompileShader(uint32_t type, const std::string& source);

		/**
		* @brief Create a shader program from vertex and fragment shaders
		* @param vertexShader Vertex shader source
		* @param fragmentShader Fragment shader source
		* @return Linked shader program ID
		*/
		uint32_t CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

		/**
		* @brief Get the location of a uniform variable
		* @param name Name of the uniform
		* @return Location ID, or -1 if not found
		*/
		int GetUniformLocation(const std::string& name);

	};
}