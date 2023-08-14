#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

enum class Season {
  kSummer,
  kAutumn,
  kWinter,
  kSpring,
};

Season Parse(const userver::formats::json::Value& value,
             userver::formats::parse::To<Season>);

}  // namespace umeteum
