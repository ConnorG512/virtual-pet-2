#include "engine/file-object.hpp"

#include <cassert>
#include <format>
#include <SDL3/SDL_iostream.h>
#include <filesystem>

Engine::File::File(const char* file_path)
{
  assert(file_path != nullptr);
  if(!std::filesystem::exists(file_path))
    throw std::runtime_error(std::format("[{}] Does not exist!", file_path));

  data_.reset(SDL_LoadFile(file_path, &size_));
  if (data_.get() == nullptr)
    throw std::runtime_error(std::format("Failed to load file! Error: {}", SDL_GetError())); 
}

auto Engine::File::GetData() noexcept -> std::span<const std::byte>
{
  return std::span<std::byte>( static_cast<std::byte*>(data_.get()), size_ );
}
