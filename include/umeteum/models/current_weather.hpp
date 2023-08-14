#pragma once

#include <umeteum/models/cloudness.hpp>
#include <umeteum/models/daytime.hpp>
#include <umeteum/models/precipitation_strength.hpp>
#include <umeteum/models/precipitation_type.hpp>
#include <umeteum/models/season.hpp>
#include <umeteum/models/weather_condition.hpp>
#include <umeteum/models/wind_direction.hpp>

#include <cstdint>
#include <string>

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

struct CurrentWeather {
  /// Температура (°C)
  double temperature;
  /// Ощущаемая температура (°C)
  double feels_like;
  /// Погодные условия
  WeatherCondition condition;
  /// Скорость ветра (в м/с)
  double wind_speed;
  /// Скорость порывов ветра (в м/с)
  double wind_gust;
  /// Направление ветра
  WindDirection wind_direction;
  /// Давление (в мм рт. ст.)
  double pressure_mm;
  /// Давление (в гектопаскалях)
  double pressure_pa;
  /// Влажность воздуха (в процентах)
  uint8_t humidity;
  /// Светлое или темное время суток
  Daytime daytime;
  /// Признак того, что время суток, указанное в поле daytime, является полярным
  bool is_polar;
  /// Время года в данном населенном пункте
  Season season;
  /// Тип осадков
  PrecipitationType precipitation_type;
  /// Сила осадков
  PrecipitationStrength precipitation_strength;
  /// Признак грозы
  bool is_thunder;
  /// Облачность
  Cloudness cloudness;
};

CurrentWeather Parse(const userver::formats::json::Value& value,
                     userver::formats::parse::To<CurrentWeather>);

}  // namespace umeteum
