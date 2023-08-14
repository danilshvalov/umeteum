#pragma once

#include <umeteum/models/units.hpp>

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

struct TemperatureRange {
  Temperature min;
  Temperature avg;
  Temperature max;
};

TemperatureRange Parse(const userver::formats::json::Value& value,
                       userver::formats::parse::To<TemperatureRange>);

}  // namespace umeteum
