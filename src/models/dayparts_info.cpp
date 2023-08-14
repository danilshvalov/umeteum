#include <umeteum/models/dayparts_info.hpp>

#include <userver/formats/json/value.hpp>

namespace umeteum {

DaypartsInfo Parse(const userver::formats::json::Value& value,
                   userver::formats::parse::To<DaypartsInfo>) {
  return DaypartsInfo{
      value["morning"].As<DaypartWeather>(),
      value["day"].As<DaypartWeather>(),
      value["evening"].As<DaypartWeather>(),
      value["night"].As<DaypartWeather>(),
  };
}

}  // namespace umeteum
