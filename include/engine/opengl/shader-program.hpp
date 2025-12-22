#pragma once

#include <cstdint>
#include <vector>

namespace Engine::OGL
{
class ShaderProgram 
{
  public:
    ShaderProgram(std::vector<std::uint32_t> shaders);

  private:

    auto compileShaders(std::vector<std::uint32_t> shaders) const noexcept -> void;
    auto attachShaders(std::vector<std::uint32_t> shaders) const noexcept -> void;
    auto deleteShaders(std::vector<std::uint32_t> shaders) const noexcept -> void;

    std::uint32_t id_{};
};
}
