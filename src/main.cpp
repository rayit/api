#include <iostream>
#include "SimpleJSON/json.hpp"
#include "api.hpp"

int main() 
{
    std::cout << "Hello C++ project!" << std::endl;

    Api api;
    json::JSON json = api.getAllDocuments();
    std::cout << json << std::endl;
    return 0;
}

