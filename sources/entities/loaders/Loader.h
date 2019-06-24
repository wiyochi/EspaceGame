#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <rapidjson/document.h>
#include "sources/entities/Machine.h"

class Loader
{
public:
	Loader();
	~Loader();
	Machine* loadMachine(std::string JSonFile);
};

