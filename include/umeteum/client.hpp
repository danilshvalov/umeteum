#pragma once

#include <umeteum/models/coords.hpp>
#include <umeteum/models/current_weather.hpp>
#include <umeteum/models/timeline_info.hpp>

#include <chrono>
#include <memory>
#include <string>

namespace userver::clients::http {
class Client;
class Response;
}  // namespace userver::clients::http

namespace userver::storages::secdist {
class Secdist;
}  // namespace userver::storages::secdist

namespace umeteum {

struct ClientConfig {
  std::string meteum_url;
  std::chrono::milliseconds timeout{0};
  int retries{1};
};

class Client final {
 public:
  Client(userver::clients::http::Client& http_client,
         userver::storages::secdist::Secdist& secdist,
         const ClientConfig& config);

  CurrentWeather FetchCurrentWeather(const Coords& coords) const;

  TimelineInfo FetchTimelineInfo(const Coords& coords) const;

 private:
  std::shared_ptr<userver::clients::http::Response> SendRequest(
      const std::string& path, const Coords& coords) const;

  userver::clients::http::Client& http_client_;
  userver::storages::secdist::Secdist& secdist_;
  const ClientConfig config_;
};

}  // namespace umeteum
