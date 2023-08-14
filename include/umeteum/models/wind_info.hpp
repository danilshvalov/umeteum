#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

enum class WindDirection {
  kCalm,
  kNorth,
  kNorthEast,
  kEast,
  kSouthEast,
  kSouth,
  kSouthWest,
  kWest,
  kNorthWest,
};

WindDirection Parse(const userver::formats::json::Value& value,
                    userver::formats::parse::To<WindDirection>);

using WindSpeed = double;

struct WindInfo {
  /// Скорость ветра (в м/с)
  WindSpeed speed;
  /// Скорость порывов ветра (в м/с)
  WindSpeed gust;
  /// Направление ветра
  WindDirection direction;
};

WindInfo Parse(const userver::formats::json::Value& value,
               userver::formats::parse::To<WindInfo>);

}  // namespace umeteum
