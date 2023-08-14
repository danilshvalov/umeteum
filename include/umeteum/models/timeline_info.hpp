#pragma once

#include <umeteum/models/timeline_weather.hpp>
#include <umeteum/models/units.hpp>

#include <vector>

namespace umeteum {

struct TimelineInfo {
  Timestamp timestamp;
  std::vector<TimelineWeather> timeline;
};

TimelineInfo Parse(const userver::formats::json::Value& value,
                   userver::formats::parse::To<TimelineInfo>);

}  // namespace umeteum
