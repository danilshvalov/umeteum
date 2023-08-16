#pragma once

#include <umeteum/exception.hpp>
#include <umeteum/models/phenom_condition.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utils/trivial_map.hpp>

namespace umeteum {

namespace {

constexpr userver::utils::TrivialBiMap kPhenomConditionString =
    [](auto selector) {
      using Condition = PhenomCondition;
      return selector()
          .Case("fog", Condition::kFog)
          .Case("mist", Condition::kMist)
          .Case("smoke", Condition::kSmoke)
          .Case("dust", Condition::kDust)
          .Case("dust-suspension", Condition::kDustSuspension)
          .Case("duststorm", Condition::kDuststorm)
          .Case("thunderstorm-with-duststorm",
                Condition::kThunderstormWithDuststorm)
          .Case("drifting-snow", Condition::kDriftingSnow)
          .Case("blowing-snow", Condition::kBlowingSnow)
          .Case("ice-pellets", Condition::kIcePellets)
          .Case("freezing-rain", Condition::kFreezingRain)
          .Case("tornado", Condition::kTornado)
          .Case("volcanic-ash", Condition::kVolcanicAsh);
    };

}  // namespace

PhenomCondition Parse(const userver::formats::json::Value& value,
                      userver::formats::parse::To<PhenomCondition>) {
  auto str = value.As<std::string>();
  if (auto result = kPhenomConditionString.TryFind(str)) {
    return *result;
  } else {
    throw InvalidArgumentException{
        fmt::format("Incorrect weather condition: \"{}\"", str),
    };
  }
}

}  // namespace umeteum
