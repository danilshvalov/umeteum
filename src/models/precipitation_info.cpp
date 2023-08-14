#include <umeteum/models/precipitation_info.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utils/trivial_map.hpp>

namespace umeteum {

namespace {

PrecipitationStrength ParsePrecipitationStrength(double value) {
  if (value < 0.25) {
    return PrecipitationStrength::kNone;
  } else if (value < 0.5) {
    return PrecipitationStrength::kLight;
  } else if (value < 0.75) {
    return PrecipitationStrength::kMedium;
  } else if (value < 1) {
    return PrecipitationStrength::kHeavy;
  } else {
    return PrecipitationStrength::kVeryHeavy;
  }
}

}  // namespace

PrecipitationType Parse(const userver::formats::json::Value& value,
                        userver::formats::parse::To<PrecipitationType>) {
  return PrecipitationType{value.As<int>()};
}

PrecipitationStrength Parse(
    const userver::formats::json::Value& value,
    userver::formats::parse::To<PrecipitationStrength>) {
  return ParsePrecipitationStrength(value.As<double>());
}

PrecipitationInfo Parse(const userver::formats::json::Value& value,
                        userver::formats::parse::To<PrecipitationInfo>) {
  return PrecipitationInfo{
      value["prec_type"].As<PrecipitationType>(),
      value["prec_strength"].As<PrecipitationStrength>(),
  };
}

}  // namespace umeteum
