#pragma once

#include <userver/formats/json_fwd.hpp>

namespace umeteum {

enum class PrecipitationType {
  /// Без осадков
  kNoPrecipitation,
  /// Дождь
  kRain,
  /// Дождь со снегом
  kSleet,
  /// Снег
  kSnow,
  /// Град
  kHail,
};

PrecipitationType Parse(const userver::formats::json::Value& value,
                        userver::formats::parse::To<PrecipitationType>);

enum class PrecipitationStrength {
  /// Без осадков
  kNone,
  /// Слабый дождь/слабый снег
  kLight,
  /// Дождь/снег
  kMedium,
  /// Сильный дождь/сильный снег
  kHeavy,
  /// Сильный ливень/очень сильный снег
  kVeryHeavy,
};

PrecipitationStrength Parse(const userver::formats::json::Value& value,
                            userver::formats::parse::To<PrecipitationStrength>);

struct PrecipitationInfo {
  /// Тип осадков
  PrecipitationType type;
  /// Сила осадков
  PrecipitationStrength strength;
};

PrecipitationInfo Parse(const userver::formats::json::Value& value,
                        userver::formats::parse::To<PrecipitationInfo>);

}  // namespace umeteum
