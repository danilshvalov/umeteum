#include <umeteum/models/weather_condition.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utils/trivial_map.hpp>
#include "umeteum/exception.hpp"

namespace umeteum {

namespace {

constexpr userver::utils::TrivialBiMap kConditionString = [](auto selector) {
  return selector()
      .Case("clear", Condition::kClear)
      .Case("partly-cloudy", Condition::kPartlyCloudy)
      .Case("cloudy-and-light-rain", Condition::kCloudyAndLightRain)
      .Case("cloudy", Condition::kCloudy)
      .Case("overcast", Condition::kOvercast)
      .Case("overcast-and-light-rain", Condition::kOvercastAndLightRain)
      .Case("light-rain", Condition::kLightRain)
      .Case("rain", Condition::kRain)
      .Case("heavy-rain", Condition::kHeavyRain)
      .Case("showers", Condition::kShowers)
      .Case("wet-snow", Condition::kWetSnow)
      .Case("light-snow", Condition::kLightSnow)
      .Case("snow", Condition::kSnow)
      .Case("snow-showers", Condition::kSnowShowers)
      .Case("hail", Condition::kHail)
      .Case("thunderstorm", Condition::kThunderstorm)
      .Case("thunderstorm-with-rain", Condition::kThunderstormWithRain)
      .Case("thunderstorm-with-hail", Condition::kThunderstormWithHail);
};

}  // namespace

Condition Parse(const userver::formats::json::Value& value,
                userver::formats::parse::To<Condition>) {
  auto str = value.As<std::string>();
  if (auto result = kConditionString.TryFind(str)) {
    return *result;
  } else {
    throw InvalidArgumentException{
        fmt::format("Incorrect weather condition: \"{}\"", str),
    };
  }
}

}  // namespace umeteum
