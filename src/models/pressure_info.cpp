#include <umeteum/models/pressure_info.hpp>

#include <userver/formats/json/value.hpp>

namespace umeteum {

PressureInfo Parse(const userver::formats::json::Value& value,
                   userver::formats::parse::To<PressureInfo>) {
  return PressureInfo{
      value["pressure_mm"].As<double>(),
      value["pressure_pa"].As<double>(),
  };
}

}  // namespace umeteum
