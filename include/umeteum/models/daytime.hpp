#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

enum class Daytime {
  kDay,
  kNight,
};

Daytime Parse(const userver::formats::json::Value& value,
              userver::formats::parse::To<Daytime>);

}  // namespace umeteum
