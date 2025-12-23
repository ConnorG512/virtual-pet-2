#pragma once 

#include <concepts>

namespace Engine::OGL
{
  template <typename T>
  concept BufferType = std::floating_point<T>;
  
  class Vertex;
  class Fragment;
  template<typename T>
  concept ShaderType = std::same_as<T, Vertex> || std::same_as<T, Fragment>; 
}
