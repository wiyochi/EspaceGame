#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <rapidjson/document.h>
#include "../Machine.hpp"
#include "../map/Grid.hpp"

namespace Loader
{
	rapidjson::Document getDocument(std::string JSonFile);

	Machine* loadMachine(std::string JSonFile);
	void loadSave(std::string JSonFile, Grid* poles[4]);
	void loadItems(std::string JSonFile);
};

