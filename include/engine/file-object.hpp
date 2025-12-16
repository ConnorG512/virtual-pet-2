#pragma once

#include "glad/glad.h"

#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_stdinc.h>
#include <cassert>
#include <concepts>
#include <cstddef>
#include <expected>
#include <memory>
#include <optional>
#include <string>

namespace Engine::Utils {
class File {
public:
  File(const char *file_path);

  File(File &&other) noexcept = delete;            // Move constructor.
  File &operator=(File &&other) noexcept = delete; // Move assignment.

  auto size() noexcept -> const std::size_t &;
  auto GetFileData() -> std::span<const std::uint8_t>;

private:
  std::unique_ptr<void, decltype(&SDL_free)> data_{nullptr, &SDL_free};
  std::size_t size_{0};
};
} // namespace Engine::Utils
