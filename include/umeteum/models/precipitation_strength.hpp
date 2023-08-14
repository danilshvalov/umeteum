#pragma once

namespace umeteum {

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

} // namespace umeteum
