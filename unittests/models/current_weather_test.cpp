#include <umeteum/models/current_weather.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utest/utest.hpp>

namespace umeteum {

UTEST(CurrentWeather, Parsing) {
  std::string json = R"json(
    {
      "temp": 20,
      "feels_like": 21,
      "condition": "overcast",
      "wind_speed": 2,
      "wind_gust": 5.9,
      "wind_dir": "n",
      "pressure_mm": 745,
      "pressure_pa": 994,
      "humidity": 83,
      "daytime": "d",
      "polar": false,
      "season": "summer",
      "prec_type": 1,
      "prec_strength": 0.25,
      "is_thunder": false,
      "cloudness": 1
    }
  )json";

  CurrentWeather expected = {
      20,
      21,
      WeatherCondition::kOvercast,
      WindInfo{
          2,
          5.9,
          WindDirection::kNorth,
      },
      PressureInfo{
          745,
          994,
      },
      Percentage{83},
      Daytime::kDay,
      false,
      Season::kSummer,
      PrecipitationInfo{
          PrecipitationType::kRain,
          PrecipitationStrength::kLight,
      },
      false,
      Cloudiness::kOvercast,
  };

  auto result = userver::formats::json::FromString(json).As<CurrentWeather>();

  EXPECT_EQ(result.temperature, expected.temperature);
  EXPECT_EQ(result.feels_like, expected.feels_like);
  EXPECT_EQ(result.condition, expected.condition);
  EXPECT_EQ(result.wind.speed, expected.wind.speed);
  EXPECT_EQ(result.wind.gust, expected.wind.gust);
  EXPECT_EQ(result.wind.direction, expected.wind.direction);
  EXPECT_EQ(result.pressure.mm, expected.pressure.mm);
  EXPECT_EQ(result.pressure.pa, expected.pressure.pa);
  EXPECT_EQ(result.humidity, expected.humidity);
  EXPECT_EQ(result.daytime, expected.daytime);
  EXPECT_EQ(result.is_polar, expected.is_polar);
  EXPECT_EQ(result.season, expected.season);
  EXPECT_EQ(result.precipitation.type, expected.precipitation.type);
  EXPECT_EQ(result.precipitation.strength, expected.precipitation.strength);
  EXPECT_EQ(result.is_thunder, expected.is_thunder);
  EXPECT_EQ(result.cloudiness, expected.cloudiness);
}

}  // namespace umeteum
