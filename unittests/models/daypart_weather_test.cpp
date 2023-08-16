#include <umeteum/models/daypart_weather.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utest/utest.hpp>

namespace umeteum {

UTEST(DaypartWeather, Parsing) {
  std::string json = R"json(
    {
       "_source": "0,1,2,3,4,5",
       "temp_min": 4,
       "temp_avg": 6,
       "temp_max": 7,
       "wind_speed": 6.8,
       "wind_gust": 12.7,
       "wind_dir": "ne",
       "pressure_mm": 761,
       "pressure_pa": 1014,
       "humidity": 92,
       "prec_period": 360,
       "cloudness": 1,
       "prec_type": 1,
       "prec_strength": 0.25,
       "icon": "ovc_-ra",
       "condition": "overcast-and-light-rain",
       "feels_like": 0,
       "daytime": "n",
       "polar": false
    }
  )json";

  DaypartWeather expected = {
      TemperatureRange{
          4,
          6,
          7,
      },
      WindInfo{
          6.8,
          12.7,
          WindDirection::kNorthEast,
      },
      PressureInfo{
          761,
          1014,
      },
      Percentage{92},
      Cloudiness::kOvercast,
      PrecipitationInfo{
          PrecipitationType::kRain,
          PrecipitationStrength::kLight,
      },
      Condition::kOvercastAndLightRain,
      0,
      Daytime::kNight,
      false,
  };

  auto result = userver::formats::json::FromString(json).As<DaypartWeather>();

  EXPECT_EQ(result.temperature.min, expected.temperature.min);
  EXPECT_EQ(result.temperature.avg, expected.temperature.avg);
  EXPECT_EQ(result.temperature.max, expected.temperature.max);
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
  EXPECT_EQ(result.precipitation.type, expected.precipitation.type);
  EXPECT_EQ(result.precipitation.strength, expected.precipitation.strength);
  EXPECT_EQ(result.cloudiness, expected.cloudiness);
}

}  // namespace umeteum
