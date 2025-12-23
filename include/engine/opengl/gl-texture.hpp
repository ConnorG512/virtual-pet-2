#pragma once 

#include "glad/glad.h"

#include <cstdint>

namespace Engine::OGL 
{
class Texture 
{
  public: 
    Texture();

    auto bindTextureToTarget(GLenum target = GL_TEXTURE_2D) const noexcept -> void;

  private:
    std::uint32_t id_{0};
    
    auto generate() noexcept -> std::uint32_t;
    auto attachTexture() const noexcept -> void;
};
}
