#pragma once 

#include <array>

namespace Utils::BasicShapes 
{
inline constexpr std::array<float, 18> FULL_SCREEN_RECTANGLE
  {
     // first triangle
     1.0f,  1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f,

     // second triangle
     1.0f, -1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f
  };
}
