#include <umeteum/models/daypart_weather.hpp>

#include <userver/formats/json/value.hpp>

namespace umeteum {

DaypartWeather Parse(const userver::formats::json::Value& value,
                     userver::formats::parse::To<DaypartWeather>) {
  return DaypartWeather{
      value.As<TemperatureRange>(),
      value.As<WindInfo>(),
      value.As<PressureInfo>(),
      value["humidity"].As<Percentage>(),
      value["cloudness"].As<Cloudiness>(),
      value.As<PrecipitationInfo>(),
      value["condition"].As<Condition>(),
      value["feels_like"].As<Temperature>(),
      value["daytime"].As<Daytime>(),
      value["polar"].As<bool>(),
  };
}

}  // namespace umeteum
