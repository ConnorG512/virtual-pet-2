#include "engine/sdl-window.hpp"
#include "glad/glad.h"
#include "engine/sdl-attributes.hpp"

#include <cassert>
#include <print>

Engine::Window::Window(std::pair<std::int32_t, std::int32_t> dimensions)
    : screen_dimensions_{dimensions} 
{
  const auto window_result = createWindow();
  if (!window_result.has_value())
    throw std::runtime_error(window_result.error());
  else 
    window_instance_.reset(window_result.value());
  
  const auto context_result = createGLContext();
  if (!context_result.has_value())
    throw std::runtime_error(context_result.error());
}

auto Engine::Window::ptr() const noexcept -> SDL_Window * {
  return window_instance_.get();
}

auto Engine::Window::resetDimentions() const noexcept -> void {
  SDL_SetWindowSize(window_instance_.get(), screen_dimensions_.first,
                    screen_dimensions_.second);
}

auto Engine::Window::getCurrentDimensions() const noexcept
    -> std::pair<std::int32_t, std::int32_t> {
  return screen_dimensions_;
}

auto Engine::Window::createWindow() const noexcept
    -> std::expected<SDL_Window *, std::string> {
  const auto [width, height] = screen_dimensions_;

  const auto result{SDL_CreateWindow("Virtual Pet 2", width, height,
                                     SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)};
  if (result == nullptr) {
    return std::unexpected(
        std::format("Failed to created SDL Window! Error: {}", SDL_GetError()));
  }

  assert(result != nullptr);
  return result;
}

auto Engine::Window::createGLContext() noexcept -> std::expected<void, std::string>
{
  context_.reset(SDL_GL_CreateContext(window_instance_.get()));
  if (context_ == nullptr)
    return std::unexpected(std::format("Failed to create context! Is Nullptr!"));

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    return std::unexpected(std::format("Failed to load GLAD"));
  }
  
  return {};
}
