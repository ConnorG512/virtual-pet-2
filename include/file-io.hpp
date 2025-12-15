#pragma once

#include <expected>
#include <string>
#include <optional>

namespace Utils::Io 
{
  auto loadFileToMemory(const char* file_path, std::optional<std::size_t*> file_size) -> std::expected<void*, std::string>;
}
