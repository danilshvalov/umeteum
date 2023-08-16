#include <umeteum/models/current_weather.hpp>

#include <umeteum/exception.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utils/trivial_map.hpp>

namespace umeteum {

CurrentWeather Parse(const userver::formats::json::Value& value,
                     userver::formats::parse::To<CurrentWeather>) {
  return CurrentWeather{
      value["temp"].As<Temperature>(),
      value["feels_like"].As<Temperature>(),
      value["condition"].As<Condition>(),
      value.As<WindInfo>(),
      value.As<PressureInfo>(),
      value["humidity"].As<Percentage>(),
      value["daytime"].As<Daytime>(),
      value["polar"].As<bool>(),
      value["season"].As<Season>(),
      value.As<PrecipitationInfo>(),
      value["is_thunder"].As<bool>(),
      value["cloudness"].As<Cloudiness>(),
      value["phenom_condition"].As<PhenomCondition>(),
  };
}

}  // namespace umeteum
