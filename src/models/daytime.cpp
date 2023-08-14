#include <umeteum/models/daytime.hpp>

#include <umeteum/exception.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/utils/trivial_map.hpp>

namespace umeteum {

namespace {

constexpr userver::utils::TrivialBiMap kDaytimeString = [](auto selector) {
  return selector().Case("d", Daytime::kDay).Case("n", Daytime::kNight);
};

}  // namespace

Daytime Parse(const userver::formats::json::Value& value,
              userver::formats::parse::To<Daytime>) {
  auto str = value.As<std::string>();
  if (auto result = kDaytimeString.TryFind(str)) {
    return *result;
  } else {
    throw InvalidArgumentException{
        fmt::format("Incorrect daytime: \"{}\"", str),
    };
  }
}

}  // namespace umeteum
