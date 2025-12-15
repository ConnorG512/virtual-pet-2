#include "file-io.hpp"

#include <SDL3/SDL_iostream.h>
#include <format>
#include <cassert>

auto Utils::Io::loadFileToMemory(const char* file_path, std::optional<std::size_t*> file_size) -> std::expected<void*, std::string>
{
  assert(file_path != nullptr);

  void* file_data {file_size.has_value() ? SDL_LoadFile(file_path, file_size.value()) : SDL_LoadFile(file_path, nullptr)};

  if (file_data == nullptr)
    return std::unexpected<std::string>(std::format("Failed to open file! Error: {}.", SDL_GetError()));
  else 
    return file_data;
}
