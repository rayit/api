#include <iostream>
#include "SimpleJSON/json.hpp"
#include "api.hpp"
#include "served/multiplexer.hpp"
#include "http_server.hpp"

int main() 
{
    std::cout << "Hello C++ project!" << std::endl;

    //Api api;
    //json::JSON json = api.getAllDocuments();
    //std::cout << json << std::endl;

    served::multiplexer multiplexer;

    rayit_api::HttpServer http_server(multiplexer);
    http_server.StartServer(); 
    return 0;
}

