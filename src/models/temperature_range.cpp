#include <umeteum/models/temperature_range.hpp>

#include <userver/formats/json/value.hpp>

namespace umeteum {

TemperatureRange Parse(const userver::formats::json::Value& value,
                       userver::formats::parse::To<TemperatureRange>) {
  return TemperatureRange{
      value["temp_min"].As<Temperature>(),
      value["temp_avg"].As<Temperature>(),
      value["temp_max"].As<Temperature>(),
  };
}

}  // namespace umeteum
