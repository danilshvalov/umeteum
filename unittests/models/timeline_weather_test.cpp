#include <umeteum/models/timeline_weather.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utest/utest.hpp>

namespace umeteum {

UTEST(TimelineWeather, Parsing) {
  std::string json = R"json(
    {
      "cloudness": 0,
      "condition": "clear",
      "icon": "skc_n",
      "is_thunder": false,
      "prec_strength": 0,
      "prec_type": 0,
      "time": "21:30",
      "ts": 1680463800
    }
  )json";

  TimelineWeather expected = {
      Cloudiness::kClear,
      Condition::kClear,
      false,
      PrecipitationInfo{
          PrecipitationType::kNoPrecipitation,
          PrecipitationStrength::kNone,
      },
      Timestamp{std::chrono::seconds{1680463800}},
  };

  auto result = userver::formats::json::FromString(json).As<TimelineWeather>();

  EXPECT_EQ(result.cloudiness, expected.cloudiness);
  EXPECT_EQ(result.condition, expected.condition);
  EXPECT_EQ(result.is_thunder, expected.is_thunder);
  EXPECT_EQ(result.precipitation.type, expected.precipitation.type);
  EXPECT_EQ(result.precipitation.strength, expected.precipitation.strength);
  EXPECT_EQ(result.timestamp, expected.timestamp);
}

}  // namespace umeteum
