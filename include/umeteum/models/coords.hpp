#pragma once

#include <userver/utils/strong_typedef.hpp>

namespace umeteum {

using Longitude = ::userver::utils::StrongTypedef<class LongitudeTag, double>;
using Latitude = ::userver::utils::StrongTypedef<class LatitudeTag, double>;

struct Coords {
  Longitude longitude;
  Latitude latitude;
};

}  // namespace umeteum
