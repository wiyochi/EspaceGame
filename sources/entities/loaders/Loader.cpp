#include "Loader.h"

namespace Loader
{
	Machine* loadMachine(std::string JSonFile)
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

		Item				in			= stringToItem(d["in"].GetString());
		Item				out			= stringToItem(d["out"].GetString());
		int					energy		= d["energy"].GetInt();
		std::string			texture		= d["texture"].GetString();
		rapidjson::Value&	vertexArray	= d["shape"];

		Machine* machine = new Machine(texture, in, out, energy);

		std::vector<sf::Vector2i>& machineShape = machine->getShape();
		for (rapidjson::SizeType i = 0; i < vertexArray.Size(); i++)
		{
			rapidjson::Value& vertex = vertexArray[i];
			machineShape.push_back(sf::Vector2i(vertex[0].GetInt(), vertex[1].GetInt()));
		}

		return machine;
	}
}