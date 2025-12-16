#pragma once 

#include <array>

namespace Utils::BasicShapes 
{
inline constexpr std::array<float, 30> FULL_SCREEN_RECTANGLE
  {
     // pos              // uv
     1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
     1.0f, -1.0f, 0.0f,  1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,

    -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,
    -1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
     1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
  };
}
