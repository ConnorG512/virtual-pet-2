#include "sdl-window.hpp"
#include "sdl-attributes.hpp"
#include "glad/glad.h"

#include <print>
#include <cassert>

Engine::SDL::Window::Window(std::pair<std::int32_t, std::int32_t> dimensions)
{
  for( const auto& [attribute, value] : ::SDL::ATTRIB_LIST)
  {
    SDL_GL_SetAttribute(attribute, value);
    std::println("Attribute: {0}, Value: {1}.", static_cast<int>(attribute), value);
  }
  
  window_instance_.reset(SDL_CreateWindow("Virtual Pet 2", dimensions.first, dimensions.second, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE));
  assert(window_instance_ != nullptr);

  context_.reset(SDL_GL_CreateContext(window_instance_.get()));
  assert(context_ != nullptr);

  if(!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
  {
    throw std::runtime_error("Failed to load GLAD!");
  }

}

auto Engine::SDL::Window::ptr() const noexcept -> SDL_Window*
{
  return window_instance_.get();
}

auto Engine::SDL::Window::resetDimentions() const noexcept -> void
{
  SDL_SetWindowSize(window_instance_.get(), 1600, 900);
}
