#include <umeteum/models/cloudiness.hpp>

#include <userver/formats/json/value.hpp>

namespace umeteum {

namespace {

Cloudiness ParseCloudiness(double value) {
  if (value < 0.25) {
    return Cloudiness::kClear;
  } else if (value < 0.5) {
    return Cloudiness::kPartly;
  } else if (value < 0.75) {
    return Cloudiness::kSignificant;
  } else if (value < 1) {
    return Cloudiness::kCloudy;
  } else {
    return Cloudiness::kOvercast;
  }
}

}  // namespace

Cloudiness Parse(const userver::formats::json::Value& value,
                 userver::formats::parse::To<Cloudiness>) {
  return ParseCloudiness(value.As<double>());
}

}  // namespace umeteum
