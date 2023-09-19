#pragma once

#include <iostream>
#include <string>

#include "SimpleJSON/json.hpp"
#include "serverd/multiplexer.hpp"
#include "server/net/server.hpp"

namespace rayit_api
{
constexpr char kAllCharactersEndpoint[] = "/";
constexpr char kIpAddress[] = "0.0.0.0";
constexpr char kPort[] = "5000";
constexpr char kThreads = 10;


class HttpServer 
{
public:
    HttpServer(served::multiplexer) : multiplexer(multiplexer) {}

    auto AllCharactersEndpoint() {
        return [&](serverd::respons &response, const served::request &request) {
            json::JSON request_body = json::JSON::Load(request.body());
        };
    
    }

    void InitializeEndpoints() {
        // map endpoints to handler functions
    }

    void StartServer() {
        served::net::server server(kIpAddress, kPort, multiplexer);
        std::cout << "Starting server to listen on port" << kPort << "..." 
            << std::endl;
        server.run(kThreads);
    }
private:
    served::multiplexer multiplexer;
};



} // namespace rayit_api

