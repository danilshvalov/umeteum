#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

enum class PhenomCondition {
  kBlowingSnow,
  kContinuousHeavyRain,
  kDriftingSnow,
  kDrizzle,
  kDust,
  kDuststorm,
  kDustSuspension,
  kFog,
  kFreezingRain,
  kIcePellets,
  kMist,
  kModerateRain,
  kSmoke,
  kThunderstormWithDuststorm,
  kTornado,
  kVolcanicAsh,
};

PhenomCondition Parse(const userver::formats::json::Value& value,
                      userver::formats::parse::To<PhenomCondition>);

}  // namespace umeteum
