#pragma once 

#include "engine/opengl/vbo.hpp"
#include "engine/opengl/vao.hpp"
#include "engine/opengl/gl-types.hpp"

namespace Engine::OGL
{
template <Engine::OGL::BufferType StoreType>
class RenderTarget
{
  public: 
    RenderTarget();

  private:
    VBO<StoreType> vbo_instance{};
    VAO vao_instance{};
};
}
