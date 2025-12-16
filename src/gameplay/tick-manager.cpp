#include "gameplay/tick-manager.hpp"

#include <cassert>

Gameplay::Ticker::Ticker(std::int32_t min, std::int32_t max, std::int32_t tick_threshold)
  : min_{min}
  , max_{max}
  , tick_threshold_{tick_threshold}
{
  assert(min_ > 0);
  assert(max_ > 0 && max_ > min_);
}

auto Gameplay::Ticker::reset() noexcept -> void 
{
  current_tick_ = 0;
}

auto Gameplay::Ticker::reachedMaxTick() const noexcept -> bool
{
  return current_tick_ == max_;
}

auto Gameplay::Ticker::increment() noexcept -> void
{
  current_tick_ += 1; 
  if (current_tick_ > max_)
    reset();
}
