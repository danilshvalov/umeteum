#include <umeteum/models/season.hpp>

#include <umeteum/exception.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utils/trivial_map.hpp>

namespace umeteum {

userver::utils::TrivialBiMap kSeasonString = [](auto selector) {
  return selector()
      .Case("summer", Season::kSummer)
      .Case("autumn", Season::kAutumn)
      .Case("winter", Season::kWinter)
      .Case("spring", Season::kSpring);
};

Season Parse(const userver::formats::json::Value& value,
             userver::formats::parse::To<Season>) {
  auto str = value.As<std::string>();
  if (auto result = kSeasonString.TryFind(str)) {
    return *result;
  } else {
    throw InvalidArgumentException{
        fmt::format("Incorrect daytime: \"{}\"", str),
    };
  }
}

}  // namespace umeteum
