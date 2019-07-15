#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "../machine/Machine.hpp"
#include "../map/Grid.hpp"
#include "../item/ItemSet.hpp"

namespace Writer
{
    void save(std::string JSonFile, Grid* poles[4]);
}
