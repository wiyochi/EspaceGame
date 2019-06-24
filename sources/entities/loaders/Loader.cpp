#include "Loader.h"

Loader::Loader()
{
}

Loader::~Loader()
{
}

Machine* Loader::loadMachine(std::string JSonFile)
{
	std::ifstream file(JSonFile, std::ios::in);
	std::string str;

	if (file)
	{
		char c;
		while (file.get(c))
			str.push_back(c);

		file.close();
	}
	else
	{
		std::cout << "Erreur load file" << std::endl;
	}

	const char* json = str.c_str();
	rapidjson::Document d;
	d.Parse(json);

	Item in = stringToItem(d["in"].GetString());
	Item out = stringToItem(d["out"].GetString());
	int energy = d["energy"].GetInt();
	std::string texture = d["texture"].GetString();

	Machine* machine = new Machine(texture, in, out, energy);

	return machine;
}
