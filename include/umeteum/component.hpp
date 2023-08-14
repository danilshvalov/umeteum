#pragma once

#include <umeteum/client.hpp>

#include <userver/components/loggable_component_base.hpp>

namespace umeteum {

class MeteumClient : public userver::components::LoggableComponentBase {
 public:
  static constexpr std::string_view kName = "meteum-client";

  MeteumClient(const userver::components::ComponentConfig&,
               const userver::components::ComponentContext&);
  ~MeteumClient() override = default;

  [[nodiscard]] Client& GetClient() const;

  static userver::yaml_config::Schema GetStaticConfigSchema();

 private:
  std::unique_ptr<Client> client_;
};

}  // namespace umeteum
