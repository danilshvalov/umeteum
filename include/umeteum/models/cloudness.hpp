#pragma once

namespace umeteum {

enum class Cloudness {
  /// Ясно
  kClear,
  /// Малооблачно
  kLittleCloudy,
  /// Облачно с прояснениями
  kCloudyWithClearings,
  /// Облачно
  kCloudy,
  /// Пасмурно
  kOvercast,
};

} // namespace umeteum
