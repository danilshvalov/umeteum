#pragma once

#include <umeteum/exception.hpp>

#include <userver/formats/json_fwd.hpp>
#include <userver/utils/strong_typedef.hpp>

namespace umeteum {

struct Percentage : userver::utils::StrongTypedef<Percentage, int> {
  using StrongTypedef::StrongTypedef;

  Percentage(double value) : StrongTypedef(value) {
    if (value < 0 || value > 100) {
      throw InvalidArgumentException{
          "Percent value cannot be less than 0 or greater than 100",
      };
    }
  }
};

Percentage Parse(const userver::formats::json::Value& value,
                 userver::formats::parse::To<Percentage>);

}  // namespace umeteum
