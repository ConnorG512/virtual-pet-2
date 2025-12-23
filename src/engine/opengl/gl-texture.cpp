#include "engine/opengl/gl-texture.hpp"

#include <cassert>

Engine::OGL::Texture::Texture()
  : id_{generate()} {}

auto Engine::OGL::Texture::generate() noexcept -> std::uint32_t
{
  std::uint32_t result {0};
  glGenTextures(1, &result);

  assert(result > 0);
  return result;
}

auto Engine::OGL::Texture::bindTextureToTarget(GLenum target) const noexcept -> void 
{
  assert(id_ > 0);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(target, id_);
}

auto Engine::OGL::Texture::attachTexture() const noexcept -> void
{
  
}
