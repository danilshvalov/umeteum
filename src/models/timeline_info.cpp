#include <umeteum/models/timeline_info.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/formats/parse/common_containers.hpp>

namespace umeteum {

TimelineInfo Parse(const userver::formats::json::Value& value,
                   userver::formats::parse::To<TimelineInfo>) {
  return TimelineInfo{
      Timestamp{value["now"].As<std::chrono::seconds>()},
      value["timeline"].As<std::vector<TimelineWeather>>(),
  };
}

}  // namespace umeteum
