#pragma once 

#include "engine/opengl/vbo.hpp"
#include "engine/opengl/vao.hpp"
#include "engine/opengl/gl-types.hpp"
#include "engine/primitive-shapes.hpp"
#include "engine/opengl/shader.hpp"
#include "engine/opengl/shader-program.hpp"
#include "glad/glad.h"

namespace Engine::OGL
{
template <typename BufferType>
class RenderTarget
{
  public: 
    RenderTarget() = default;

    auto draw() const noexcept -> void 
    {
      glUseProgram(program_.getID());
      glBindVertexArray(vao_instance.get());
      glDrawArrays(GL_TRIANGLES, 0, 6);
    }

  private:
    VBO<BufferType> vbo_instance{Utils::BasicShapes::FULL_SCREEN_RECTANGLE};
    VAO vao_instance{};
    Shader<Engine::OGL::Vertex> vertex_shader{"src/shaders/default.vert"};
    Shader<Engine::OGL::Fragment> fragment_shader{"src/shaders/default.frag"};
    ShaderProgram program_{
      {vertex_shader.getID(), fragment_shader.getID()}
    };
};
}
