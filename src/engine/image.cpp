#include "engine/image.hpp"

#include <cassert>
#include <stdexcept>
#include <format>

Engine::Image::Image(const char* file_path)
{
  assert(file_path != nullptr);

  image_.reset(IMG_Load(file_path)); 
  if (image_.get() == nullptr)
    throw std::runtime_error(std::format("Failed to load image! Error: {}", SDL_GetError()));
}

auto Engine::Image::data() noexcept -> const SDL_Surface*
{
  return image_.get();
}
