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
      2,
      5.9,
      WindDirection::kNorth,
      745,
      994,
      83,
      Daytime::kDay,
      false,
      Season::kSummer,
      PrecipitationType::kRain,
      PrecipitationStrength::kLight,
      false,
      Cloudness::kOvercast,
  };

  auto result = formats::json::FromString(json).As<CurrentWeather>();

  EXPECT_EQ(result.temperature, expected.temperature);
  EXPECT_EQ(result.feels_like, expected.feels_like);
  EXPECT_EQ(result.condition, expected.condition);
  EXPECT_EQ(result.wind_speed, expected.wind_speed);
  EXPECT_EQ(result.wind_gust, expected.wind_gust);
  EXPECT_EQ(result.wind_direction, expected.wind_direction);
  EXPECT_EQ(result.pressure_mm, expected.pressure_mm);
  EXPECT_EQ(result.pressure_pa, expected.pressure_pa);
  EXPECT_EQ(result.humidity, expected.humidity);
  EXPECT_EQ(result.daytime, expected.daytime);
  EXPECT_EQ(result.is_polar, expected.is_polar);
  EXPECT_EQ(result.season, expected.season);
  EXPECT_EQ(result.precipitation_type, expected.precipitation_type);
  EXPECT_EQ(result.precipitation_strength, expected.precipitation_strength);
  EXPECT_EQ(result.is_thunder, expected.is_thunder);
  EXPECT_EQ(result.cloudness, expected.cloudness);
}

} // namespace umeteum
