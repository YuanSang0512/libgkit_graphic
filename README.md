# libgkit_graphic

Graphic module for libgkit - a modern C++20 graphics library providing OpenGL rendering interfaces.

## Repository Overview

This library provides a clean abstraction layer over OpenGL, designed with future Vulkan support in mind. The architecture follows a modular design with clear separation between core interfaces and backend implementations.

```
src/
├── core/           # Core rendering interfaces (gkit::graphic)
│   ├── Renderer.hpp    # Main rendering interface
│   └── Shader.hpp      # Shader program wrapper
├── openGL/         # OpenGL implementations (gkit::graphic::opengl)
│   ├── VertexArray.hpp
│   ├── VertexBuffer.hpp
│   ├── IndexBuffer.hpp
│   ├── VertexBufferLayout.hpp
│   ├── Texture.hpp
│   ├── FrameBuffer.hpp
│   ├── RenderBuffer.hpp
│   ├── StateManager.hpp
│   └── config.hpp      # Configuration (texture types, screen size)
└── debug/          # Debug utilities (GLCall macro, error logging)
```

## Drawing Interface

The primary rendering entry point is the `gkit::graphic::Renderer` class:

```cpp
gkit::graphic::Renderer renderer;

// Clear framebuffer
renderer.Clear();

// Draw indexed geometry
renderer.Draw(vertexArray, indexBuffer, shader);

// Draw non-indexed geometry
renderer.Draw(vertexArray, shader);

// Draw instanced geometry
renderer.DrawInstance(vertexArray, indexBuffer, shader, instanceCount);
```

### Basic Usage Flow

1. **Create vertex data** - Use `VertexBuffer` to upload geometry
2. **Define layout** - Use `VertexBufferLayout` to specify attribute organization
3. **Create vertex array** - Combine buffers with `VertexArray::AddBuffer()`
4. **Create index buffer** - Use `IndexBuffer` for indexed rendering
5. **Load shaders** - Create `Shader` from file
6. **Render** - Call `Renderer::Draw()` with VA, IB, and Shader

## Dependencies

### Current temporary Dependencies (in test/extern/)

- **GLM** - Mathematics library 
- **stb_image** - Image loading for textures
- **GLFW** - Window creation and input handling 

> **Note for merging into main library**: 
> - The `src` module currently depends on GLM and stb_image which are located in `test/extern/`. When merging into the main libgkit repository, these dependencies should be properly integrated as submodule dependencies or moved to a suitable location in the main library.
> - The debug system (`src/debug/`) is currently using a temporary implementation and should be replaced with the main library's logging/debug infrastructure when merging.
> - `SCR_WIDTH` and `SCR_HEIGHT` used in FrameBuffer, RenderBuffer, Texture are currently hardcoded in config.hpp. Should be dynamically obtained from window size in the future.

## TODO (Before merging into main library)

- [ ] Adapt main library's math library (replace GLM dependency)
- [ ] Remove temporary debug system (`src/debug/`)
- [ ] Remove test folder
- [ ] Remove temporary shader file parsing and texture loading (replace with main library's file I/O, adapt resource reading format, further encapsulate rendering interfaces)

## Build Requirements

- C++20 compatible compiler
- CMake 3.16+
- OpenGL 4.5+ capable graphics driver