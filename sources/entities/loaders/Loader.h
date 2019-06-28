#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <rapidjson/document.h>
#include "../Machine.h"
#include "../map/Grid.h"

namespace Loader
{
	rapidjson::Document getDocument(std::string JSonFile);

	Machine* loadMachine(std::string JSonFile);
	void loadSave(std::string JSonFile, Grid* poles[4]);
};

