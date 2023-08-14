#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

enum class WeatherCondition {
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

WeatherCondition Parse(const userver::formats::json::Value& value,
                       userver::formats::parse::To<WeatherCondition>);

}  // namespace umeteum
