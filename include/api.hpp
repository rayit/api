#pragma once

#include <cstdint>
#include <string>
#include <iostream>

#include "SimpleJSON/json.hpp"

class Api
{

public: 
    json::JSON getAllDocuments() {
        json::JSON result;
        result["characters"] = json::Array();
        return result;
    }
};

