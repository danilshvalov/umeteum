#pragma once

#include <umeteum/models/cloudiness.hpp>
#include <umeteum/models/daytime.hpp>
#include <umeteum/models/percentage.hpp>
#include <umeteum/models/precipitation_info.hpp>
#include <umeteum/models/pressure_info.hpp>
#include <umeteum/models/season.hpp>
#include <umeteum/models/units.hpp>
#include <umeteum/models/weather_condition.hpp>
#include <umeteum/models/wind_info.hpp>

#include <cstdint>
#include <string>

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

struct CurrentWeather {
  /// Температура (°C)
  Temperature temperature;
  /// Ощущаемая температура (°C)
  Temperature feels_like;
  /// Погодные условия
  WeatherCondition condition;
  /// Информация о ветре
  WindInfo wind;
  /// Информация о давлении
  PressureInfo pressure;
  /// Влажность воздуха (в процентах)
  Percentage humidity;
  /// Светлое или темное время суток
  Daytime daytime;
  /// Признак того, что время суток, указанное в поле daytime, является полярным
  bool is_polar;
  /// Время года в данном населенном пункте
  Season season;
  /// Информация об осадках
  PrecipitationInfo precipitation;
  /// Признак грозы
  bool is_thunder;
  /// Облачность
  Cloudiness cloudiness;
};

CurrentWeather Parse(const userver::formats::json::Value& value,
                     userver::formats::parse::To<CurrentWeather>);

}  // namespace umeteum
