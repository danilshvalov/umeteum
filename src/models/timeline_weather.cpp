#include <umeteum/models/timeline_weather.hpp>

#include <userver/formats/json/value.hpp>

namespace umeteum {

TimelineWeather Parse(const userver::formats::json::Value& value,
                      userver::formats::parse::To<TimelineWeather>) {
  return TimelineWeather{
      value["cloudness"].As<Cloudiness>(),
      value["condition"].As<Condition>(),
      value["is_thunder"].As<bool>(),
      value.As<PrecipitationInfo>(),
      Timestamp{value["ts"].As<std::chrono::seconds>()},
  };
}

}  // namespace umeteum
