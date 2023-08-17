#pragma once

#include <umeteum/models/cloudiness.hpp>
#include <umeteum/models/condition.hpp>
#include <umeteum/models/daytime.hpp>
#include <umeteum/models/percentage.hpp>
#include <umeteum/models/precipitation_info.hpp>
#include <umeteum/models/pressure_info.hpp>
#include <umeteum/models/temperature_range.hpp>
#include <umeteum/models/units.hpp>
#include <umeteum/models/wind_info.hpp>

namespace umeteum {

struct DaypartWeather {
  TemperatureRange temperature;
  WindInfo wind;
  PressureInfo pressure;
  Percentage humidity;
  Cloudiness cloudiness;
  PrecipitationInfo precipitation;
  Condition condition;
  Temperature feels_like;
  Daytime daytime;
  bool is_polar;
};

DaypartWeather Parse(const userver::formats::json::Value& value,
                     userver::formats::parse::To<DaypartWeather>);

}  // namespace umeteum
