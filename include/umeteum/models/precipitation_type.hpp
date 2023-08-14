#pragma once

namespace umeteum {

enum class PrecipitationType {
  /// Без осадков
  kNoPrecipitation,
  /// Дождь
  kRain,
  /// Дождь со снегом
  kRainAndSnow,
  /// Снег
  kSnow,
  /// Град
  kHail,
};

} // namespace umeteum
