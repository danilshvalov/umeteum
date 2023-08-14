#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

struct PressureInfo {
  /// Давление (в мм рт. ст.)
  double mm;
  /// Давление (в гектопаскалях)
  double pa;
};

PressureInfo Parse(const userver::formats::json::Value& value,
                   userver::formats::parse::To<PressureInfo>);

}  // namespace umeteum
