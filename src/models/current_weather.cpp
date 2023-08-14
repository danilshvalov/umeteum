#include <umeteum/models/current_weather.hpp>

#include <umeteum/exception.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utils/trivial_map.hpp>

namespace umeteum {

namespace {

namespace utils = userver::utils;

template <typename Map>
typename Map::Second ParseEnumType(std::string_view str, const Map &map) {
  if (auto condition = map.TryFind(str)) {
    return *condition;
  } else {
    throw ParseException{
        fmt::format("Incorrect value: \"{}\"", str),
    };
  }
}

constexpr utils::TrivialBiMap kWeatherConditionString = [](auto selector) {
  using Condition = WeatherCondition;
  return selector()
      .Case("clear", Condition::kClear)
      .Case("partly-cloudy", Condition::kPartlyCloudy)
      .Case("cloudy-and-light-rain", Condition::kCloudyAndLightRain)
      .Case("cloudy", Condition::kCloudy)
      .Case("overcast", Condition::kOvercast)
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

constexpr utils::TrivialBiMap kSeasonString = [](auto selector) {
  return selector()
      .Case("summer", Season::kSummer)
      .Case("autumn", Season::kAutumn)
      .Case("winter", Season::kWinter)
      .Case("spring", Season::kSpring);
};

constexpr utils::TrivialBiMap kDaytimeString = [](auto selector) {
  return selector().Case("d", Daytime::kDay).Case("n", Daytime::kNight);
};

constexpr utils::TrivialBiMap kWindDirectionString = [](auto selector) {
  using Direction = WindDirection;
  return selector()
      .Case("nw", Direction::kNorthWest)
      .Case("n", Direction::kNorth)
      .Case("ne", Direction::kNorthEast)
      .Case("e", Direction::kEast)
      .Case("se", Direction::kSouthEast)
      .Case("s", Direction::kSouth)
      .Case("sw", Direction::kSouthWest)
      .Case("w", Direction::kWest)
      .Case("c", Direction::kCalm);
};

PrecipitationStrength ParsePrecipitationStrength(double value) {
  if (value < 0.25) {
    return PrecipitationStrength::kNone;
  } else if (value < 0.5) {
    return PrecipitationStrength::kLight;
  } else if (value < 0.75) {
    return PrecipitationStrength::kMedium;
  } else if (value < 1) {
    return PrecipitationStrength::kHeavy;
  } else {
    return PrecipitationStrength::kVeryHeavy;
  }
}

Cloudness ParseCloudness(double value) {
  if (value < 0.25) {
    return Cloudness::kClear;
  } else if (value < 0.5) {
    return Cloudness::kLittleCloudy;
  } else if (value < 0.75) {
    return Cloudness::kCloudyWithClearings;
  } else if (value < 1) {
    return Cloudness::kCloudy;
  } else {
    return Cloudness::kOvercast;
  }
}

} // namespace

CurrentWeather Parse(const userver::formats::json::Value &value,
                     userver::formats::parse::To<CurrentWeather>) {
  return CurrentWeather{
      value["temp"].As<double>(),
      value["feels_like"].As<double>(),
      ParseEnumType(value["condition"].As<std::string>(),
                    kWeatherConditionString),
      value["wind_speed"].As<double>(),
      value["wind_gust"].As<double>(),
      ParseEnumType(value["wind_dir"].As<std::string>(), kWindDirectionString),
      value["pressure_mm"].As<double>(),
      value["pressure_pa"].As<double>(),
      value["humidity"].As<uint8_t>(),
      ParseEnumType(value["daytime"].As<std::string>(), kDaytimeString),
      value["polar"].As<bool>(),
      ParseEnumType(value["season"].As<std::string>(), kSeasonString),
      PrecipitationType{value["prec_type"].As<int>()},
      ParsePrecipitationStrength(value["prec_strength"].As<double>()),
      value["is_thunder"].As<bool>(),
      ParseCloudness(value["cloudness"].As<double>()),
  };
}

} // namespace umeteum
