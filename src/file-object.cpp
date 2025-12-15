#include "file-object.hpp"

#include <stdexcept>
#include <format>

Engine::Utils::File::File(const char* file_path)
{
  assert(file_path != nullptr);
  data_.reset(SDL_LoadFile(file_path, &size_));
  assert(size_ > 0);
}

auto Engine::Utils::File::size() noexcept -> const std::size_t&
{
  return size_;
}

auto Engine::Utils::File::GetFileData() -> std::span<const std::uint8_t>
{
  assert(data_.get() != nullptr);
  return std::span<const std::uint8_t>(
        static_cast<const std::uint8_t*>(data_.get()),
        size_
      );
}
