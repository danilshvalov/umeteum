#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

enum class Cloudiness {
  /// Ясно
  kClear,
  /// Малооблачно
  kPartly,
  /// Облачно с прояснениями
  kSignificant,
  /// Облачно
  kCloudy,
  /// Пасмурно
  kOvercast,
};

Cloudiness Parse(const userver::formats::json::Value& value,
                 userver::formats::parse::To<Cloudiness>);

}  // namespace umeteum
