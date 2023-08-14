#pragma once

#include <umeteum/models/daypart_weather.hpp>

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

struct DaypartsInfo {
  DaypartWeather morning;
  DaypartWeather day;
  DaypartWeather evening;
  DaypartWeather night;
};

DaypartsInfo Parse(const userver::formats::json::Value& value,
                   userver::formats::parse::To<DaypartsInfo>);

}  // namespace umeteum
