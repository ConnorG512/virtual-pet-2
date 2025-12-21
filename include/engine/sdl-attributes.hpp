#pragma once

#include <SDL3/SDL.h>
#include <array>
#include <cstdint>

namespace Engine {
class Attributes 
{
  public:
    Attributes();

  private:
    std::array<std::pair<SDL_GLAttr, std::int32_t>, 3> attrib_list_ = {{
      {SDL_GL_CONTEXT_MAJOR_VERSION, 3},
      {SDL_GL_CONTEXT_MINOR_VERSION, 3},
      {SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE},
    }};
};
}
