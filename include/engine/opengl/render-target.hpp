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

    auto draw(
        GLsizei vertex_num, 
        GLenum draw_mode = GL_TRIANGLES, 
        GLint first_element_pos = 0) const noexcept -> void 
    {
      glUseProgram(program_.getID());
      glBindVertexArray(vao_instance.get());
      glDrawArrays(
          draw_mode, 
          first_element_pos, 
          vertex_num
      );
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
