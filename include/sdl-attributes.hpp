#pragma once

#include <array>
#include <SDL3/SDL.h>
#include <cstdint>

namespace SDL {
  [[maybe_unused]] inline static constexpr auto ATTRIB_LIST = std::to_array<std::pair<SDL_GLAttr, std::int32_t>>
  ({
    {SDL_GL_CONTEXT_MAJOR_VERSION, 3},
    {SDL_GL_CONTEXT_MINOR_VERSION, 3},
    {SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE},
  });
}
