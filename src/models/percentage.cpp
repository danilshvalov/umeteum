#include <umeteum/models/percentage.hpp>

#include <userver/formats/json/value.hpp>

namespace umeteum {

Percentage Parse(const userver::formats::json::Value& value,
                 userver::formats::parse::To<Percentage>) {
  return Percentage{value.As<Percentage::UnderlyingType>()};
}

}  // namespace umeteum
