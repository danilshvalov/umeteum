#include <umeteum/exception.hpp>
#include <umeteum/models/condition.hpp>

#include <unordered_map>

#include <userver/formats/json/value.hpp>

namespace umeteum {

namespace {

const std::unordered_map<std::string, Condition> kConditionString = {
    {"clear", Condition::kClear},
    {"partly-cloudy", Condition::kPartlyCloudy},
    {"cloudy", Condition::kCloudy},
    {"overcast", Condition::kOvercast},
    {"light-rain", Condition::kLightRain},
    {"rain", Condition::kRain},
    {"heavy-rain", Condition::kHeavyRain},
    {"showers", Condition::kShowers},
    {"wet-snow", Condition::kWetSnow},
    {"light-snow", Condition::kLightSnow},
    {"snow", Condition::kSnow},
    {"snow-showers", Condition::kSnowShowers},
    {"hail", Condition::kHail},
    {"thunderstorm", Condition::kThunderstorm},
    {"thunderstorm-with-rain", Condition::kThunderstormWithRain},
    {"thunderstorm-with-hail", Condition::kThunderstormWithHail},
};

}  // namespace

Condition Parse(const userver::formats::json::Value& value,
                userver::formats::parse::To<Condition>) {
  auto str = value.As<std::string>();
  if (auto it = kConditionString.find(str); it != kConditionString.end()) {
    return it->second;
  }
  for (const auto& [key, value] : kConditionString) {
    if (str.find(key) == 0) {
      return value;
    }
  }
  throw InvalidArgumentException{
      fmt::format("Incorrect weather condition: \"{}\"", str),
  };
}

}  // namespace umeteum
