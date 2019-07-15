#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <rapidjson/document.h>
#include "../machine/Machine.hpp"
#include "../map/Grid.hpp"
#include "../item/ItemSet.hpp"
#include "../skillTree/Node.hpp"
#include "../skillTree/Tree.hpp"

#define MACHINE_PATH "resources/machine/"

namespace Loader
{
	rapidjson::Document getDocument(std::string JSonFile);

	ItemSet* 	loadItemSet			(rapidjson::Value& arrayItemSet);
	Machine* 	loadMachine			(std::string JSonFile);
	void 		loadSave			(std::string JSonFile, Grid* poles[4]);
	void 		loadMachineArray	(rapidjson::Value& machineArray, Grid* pole);
	void 		loadItems			(std::string JSonFile);
	Tree* 		loadSkillTree		(std::string JSonFile);
};

