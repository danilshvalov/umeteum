#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

enum class Condition {
  kClear,
  kPartlyCloudy,
  kCloudyAndLightRain,
  kCloudy,
  kOvercast,
  kOvercastAndLightRain,
  kLightRain,
  kRain,
  kHeavyRain,
  kShowers,
  kWetSnow,
  kLightSnow,
  kSnow,
  kSnowShowers,
  kHail,
  kThunderstorm,
  kThunderstormWithRain,
  kThunderstormWithHail,
};

Condition Parse(const userver::formats::json::Value& value,
                userver::formats::parse::To<Condition>);

}  // namespace umeteum
