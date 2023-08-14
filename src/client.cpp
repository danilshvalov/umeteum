#include <umeteum/client.hpp>

#include <umeteum/models/coords.hpp>
#include <umeteum/models/current_weather.hpp>

#include <fmt/format.h>
#include <userver/clients/http/client.hpp>
#include <userver/formats/json/value.hpp>
#include <userver/http/header_map.hpp>
#include <userver/http/url.hpp>
#include <userver/storages/secdist/secdist.hpp>

namespace umeteum {

namespace {

namespace http = userver::http;
namespace json = userver::formats::json;

class MeteumSecdist {
 public:
  using ApiKey = userver::utils::NonLoggable<class ApiKeyTag, std::string>;

  MeteumSecdist(const json::Value& doc) {
    auto config = doc["meteum"];
    api_key_ = config["api_key"].As<ApiKey>();
  }

  const ApiKey& GetApiKey() const { return api_key_; }

 private:
  ApiKey api_key_;
};

}  // namespace

Client::Client(userver::clients::http::Client& http_client,
               userver::storages::secdist::Secdist& secdist,
               const ClientConfig& config)
    : http_client_(http_client), secdist_(secdist), config_(config) {}

CurrentWeather Client::FetchCurrentWeather(const Coords& coords) const {
  auto response = SendRequest("/fact", coords);
  return json::FromString(response->body()).As<CurrentWeather>();
}

TimelineInfo Client::FetchTimelineInfo(const Coords& coords) const {
  auto response = SendRequest("/nowcast/timeline", coords);
  return json::FromString(response->body()).As<TimelineInfo>();
}

std::shared_ptr<userver::clients::http::Response> Client::SendRequest(
    const std::string& path, const Coords& coords) const {
  auto secdist_snapshot = secdist_.GetSnapshot();
  const auto secdist = secdist_snapshot->Get<MeteumSecdist>();
  http::headers::HeaderMap headers = {
      {"X-Meteum-API-Key", secdist.GetApiKey().GetUnderlying()},
  };

  http::Args args = {
      {"lon", std::to_string(coords.longitude.GetUnderlying())},
      {"lat", std::to_string(coords.latitude.GetUnderlying())},
  };

  std::string url =
      http::MakeUrl(fmt::format("{}{}", config_.meteum_url, path), args);
  return http_client_.CreateRequest()
      .get(url)
      .headers(headers)
      .retry(config_.retries)
      .timeout(config_.timeout)
      .perform();
}

}  // namespace umeteum
