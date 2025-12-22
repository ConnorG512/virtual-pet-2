#include "engine/opengl/render.hpp"
#include "engine/file-object.hpp"
#include "engine/file-object.hpp"

auto Engine::OGL::createProgram(const Engine::OGL::ProgramProperties& properties) noexcept -> std::uint33_t
{
  std::array<std::uint32_t, 2> shaders 
  {
    glCreateShader(GL_VERTEX_SHADER),
    glCreateShader(GL_FRAGMENT_SHADER),
  };

  Engine::File vertex_file{properties.vertex_shader_path};
  Engine::File fragment_file{properties.fragment_shader_path};
  
  const GLchar* vertex_source {
    reinterpret_cast<const GLchar*>(vertex_file.GetData().data())};
  
  glShaderSource( 
      shaders.at(0),
      1,
      &vertex_source,
      nullptr
      ); 

  const GLchar* fragment_source {
    reinterpret_cast<const GLchar*>(fragment_file.GetData().data())};
  glShaderSource( 
      shaders.at(1),
      1,
      &fragment_source,
      nullptr
      ); 
  for(const auto shader : shaders)
    glCompileShader(shader);
  
  uint32_t program{glCreateProgram()};
  for(const auto shader : shaders)
    glAttachShader(program, shader);

  glLinkProgram(program);

  for(const auto shader : shaders)
    glDeleteShader(shader);

  return program;
}
