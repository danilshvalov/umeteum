#pragma once

#include <umeteum/models/cloudiness.hpp>
#include <umeteum/models/precipitation_info.hpp>
#include <umeteum/models/units.hpp>
#include <umeteum/models/condition.hpp>

#include <chrono>

namespace umeteum {

struct TimelineWeather {
  Cloudiness cloudiness;
  Condition condition;
  bool is_thunder;
  PrecipitationInfo precipitation;
  Timestamp timestamp;
};

TimelineWeather Parse(const userver::formats::json::Value& value,
                      userver::formats::parse::To<TimelineWeather>);

}  // namespace umeteum
