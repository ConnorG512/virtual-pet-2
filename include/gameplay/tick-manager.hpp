#pragma once 

#include <cstdint>

namespace Gameplay 
{
  class Ticker 
  {
    public:
      Ticker(std::int32_t min, std::int32_t max, std::int32_t tick_threshold = 60);
      ~Ticker() = default;
      
      auto currentCount() const noexcept -> std::int32_t;
      auto reset() noexcept -> void;
      auto reachedMaxTick() const noexcept -> bool;
      
    private:
      auto increment() noexcept -> void;

      std::int32_t current_tick_{0};
      std::int32_t min_ {0};
      std::int32_t max_ {300};
      std::int32_t tick_threshold_{60};
  };
}
