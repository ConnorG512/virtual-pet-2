#include "engine/sdl-gl-context.hpp"
#include "glad/glad.h"

#include <cassert>

Engine::SDLGLContext::SDLGLContext(SDL_Window* window_instance)
{
  const auto result {createContext(window_instance)};
  if (!result.has_value())
    throw std::runtime_error(result.error());
}

auto Engine::SDLGLContext::createContext(SDL_Window* window_instance) noexcept -> std::expected<void, std::string> 
{
  assert(window_instance != nullptr);

  context_.reset(SDL_GL_CreateContext(window_instance));
  if (context_ == nullptr)
    return std::unexpected(std::format("Failed to create context!"));

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    return std::unexpected(std::format("Failed to load GLAD"));
  }
  
  return {};
}
