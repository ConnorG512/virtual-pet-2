#pragma once 

#include "glad/glad.h"
#include "engine/file-object.hpp"

#include <cstdint>
#include <span>
#include <cassert>
#include <vector>

namespace Engine::OGL 
{
  struct ProgramProperties 
  {
    const char* vertex_shader_path {};
    const char* fragment_shader_path {};
  };
  auto createProgram(const ProgramProperties& properties) noexcept -> std::uint32_t;
  auto attachAndLinkToProgram(std::uint32_t program, std::vector<std::uint32_t> shader_list) noexcept -> void;
  auto deleteShaders(std::vector<std::uint32_t> shader_list) noexcept -> void;
}
