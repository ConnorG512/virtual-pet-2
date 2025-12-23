#pragma once

#include "glad/glad.h"
#include "engine/file-object.hpp"
#include "engine/opengl/gl-types.hpp"

#include <span>
#include <concepts>

namespace Engine::OGL
{

template <typename ShaderType>
class Shader
{
  public: 
    explicit Shader(const char* file_path)
      : id_{createShader()}
    {
      const std::span<const GLchar>shader_source {loadFile(file_path)};
      const GLchar* shader_source_ptr {shader_source.data()};
      const GLint shader_source_size {static_cast<GLint>(shader_source.size())};
      
      if(id_ == 0)
        throw std::runtime_error("Failed to create shader!");

      glShaderSource(
            id_,
            1,
            &shader_source_ptr,
            &shader_source_size
          );
    }

    auto getID() const noexcept -> std::uint32_t 
    {
      return id_;
    }

  private:
    auto loadFile(const char* file_path) const noexcept -> std::span<const GLchar> 
    {
      Engine::File shader_file{file_path};
      const GLchar* shader_source {reinterpret_cast<const GLchar*>(shader_file.GetData().data())};
      
      return
      {
        shader_source,
        shader_file.GetData().size(),
      };
    }

    auto createShader() const noexcept -> std::uint32_t 
    {
      if constexpr (std::same_as<ShaderType, Engine::OGL::Vertex>)
        return glCreateShader(GL_VERTEX_SHADER);
      if constexpr (std::same_as<ShaderType, Engine::OGL::Fragment>)
        return glCreateShader(GL_FRAGMENT_SHADER);
    }

    std::uint32_t id_{};
};
}
