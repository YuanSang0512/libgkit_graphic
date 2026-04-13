#pragma once
#ifndef CONFIG_H
#define CONFIG_H

namespace gkit::graphic::opengl{

	const unsigned int SCR_WIDTH = 500;
	const unsigned int SCR_HEIGHT = 500;

	/// <summary>
	/// 纹理模式
	/// </summary>
	enum class TextureType
	{
		TEXTURE_2D,
		TEXTURE_CUBE_MAP,
		TEXTURE_FRAMEBUFFER
	};
}

namespace gkit::graphic::opengl::window {

	/// <summary>
	/// Set viewport with custom position and size
	/// </summary>
	auto SetViewport(int x, int y, int width, int height) -> void;

	/// <summary>
	/// Set viewport with custom size (origin at 0, 0)
	/// </summary>
	auto SetViewport(int width, int height) -> void;

}
#endif