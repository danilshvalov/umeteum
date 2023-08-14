#include <umeteum/models/wind_info.hpp>

#include <umeteum/exception.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utils/trivial_map.hpp>

namespace umeteum {

namespace {

constexpr userver::utils::TrivialBiMap kWindDirectionString =
    [](auto selector) {
      using Direction = WindDirection;
      return selector()
          .Case("c", Direction::kCalm)
          .Case("nw", Direction::kNorthWest)
          .Case("n", Direction::kNorth)
          .Case("ne", Direction::kNorthEast)
          .Case("e", Direction::kEast)
          .Case("se", Direction::kSouthEast)
          .Case("s", Direction::kSouth)
          .Case("sw", Direction::kSouthWest)
          .Case("w", Direction::kWest);
    };

}  // namespace

WindDirection Parse(const userver::formats::json::Value& value,
                    userver::formats::parse::To<WindDirection>) {
  auto str = value.As<std::string>();
  if (auto result = kWindDirectionString.TryFind(str)) {
    return *result;
  } else {
    throw InvalidArgumentException{
        fmt::format("Incorrect daytime: \"{}\"", str),
    };
  }
}

WindInfo Parse(const userver::formats::json::Value& value,
               userver::formats::parse::To<WindInfo>) {
  return WindInfo{
      value["wind_speed"].As<double>(),
      value["wind_gust"].As<double>(),
      value["wind_dir"].As<WindDirection>(),
  };
}

}  // namespace umeteum
