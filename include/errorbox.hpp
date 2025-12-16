#pragma once 

#include <expected>
#include <string>
#include <optional>
#include <SDL3/SDL.h>
#include <SDL3/SDL_messagebox.h>
#include <utility>
#include <cassert>

namespace Engine::ErrorBox 
{
  enum class BoxType 
  {
    error = SDL_MESSAGEBOX_ERROR,
    warning = SDL_MESSAGEBOX_WARNING,
    information = SDL_MESSAGEBOX_INFORMATION,
  };
  
  template<Engine::ErrorBox::BoxType box_type>
  auto CreateErrorBox(
      const char* message, 
      std::optional<SDL_Window*> window = std::nullopt 
      ) noexcept -> std::expected<void, std::string>
  {
    assert(message != nullptr);

    constexpr const char* box_title = []() consteval -> const char *
    {
      if constexpr (box_type == Engine::ErrorBox::BoxType::error)
        return "Error:";
      else if constexpr (box_type == Engine::ErrorBox::BoxType::warning)
        return "Warning:";
      else if constexpr (box_type == Engine::ErrorBox::BoxType::information)
        return "Information:";
      else 
        static_assert("Not a valid box type!");
    }();
    
    const bool message_box_result = SDL_ShowSimpleMessageBox(
        std::to_underlying(box_type),
        box_title,
        message,
        window.value_or(nullptr)
        );

    if (!message_box_result)
      return std::unexpected("Failed to create message box!");

    return {};
  }
}
