#include "Loader.hpp"

namespace Loader
{
	rapidjson::Document getDocument(std::string JSonFile)
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

		return d;
	}

	ItemSet* loadItemSet(rapidjson::Value& arrayItemSet)
	{
		std::vector<std::vector<Item*>> items;
		std::vector<std::vector<int>> quantity;
		for (rapidjson::SizeType i = 0; i < arrayItemSet.Size(); i++)
		{
			std::vector<Item*> vec;
			std::vector<int> vecInt;
			if(arrayItemSet[i].GetType() == rapidjson::Type::kArrayType)
			{
				for (rapidjson::SizeType j = 0; j < arrayItemSet[i].Size(); j++)
				{
					vec.push_back(Item::findItem(arrayItemSet[i][j]["item"].GetString()));
					vecInt.push_back(arrayItemSet[i][j]["quantity"].GetInt());
				}
			}
			else
			{
				vec.push_back(Item::findItem(arrayItemSet[i]["item"].GetString()));
				vecInt.push_back(arrayItemSet[i]["quantity"].GetInt());
			}
			items.push_back(vec);
			quantity.push_back(vecInt);
		}
		return new ItemSet(items, quantity);
	}

	Machine* loadMachine(std::string JSonFile)
	{
		rapidjson::Document d = getDocument(JSonFile);

		ItemSet*			in			= loadItemSet(d["in"]);
		ItemSet*			out			= loadItemSet(d["out"]);
		int					energy		= d["energy"].GetInt();
		std::string			texture		= d["texture"].GetString();
		rapidjson::Value&	vertexArray	= d["shape"];

		Machine* machine = new Machine(texture, energy);
		machine->setIn(in);
		machine->setOut(out);

		std::vector<sf::Vector2i>& machineShape = machine->getShape();
		for (rapidjson::SizeType i = 0; i < vertexArray.Size(); i++)
		{
			rapidjson::Value& vertex = vertexArray[i];
			machineShape.push_back(sf::Vector2i(vertex[0].GetInt(), vertex[1].GetInt()));
		}

		return machine;
	}

	void loadSave(std::string JSonFile, Grid* poles[4])
	{
		rapidjson::Document d = getDocument(JSonFile);

		// Pole mine
		poles[0] = new Grid(20, 20, sf::Vector2f(0.f, 0.f), sf::Vector2f(20.f, 20.f));
		poles[0]->setName("mine");
		rapidjson::Value& machineArray = d["mine"]["machines"];
		loadMachineArray(machineArray, poles[0]);

		// Pole factory
		poles[1] = new Grid(20, 20, sf::Vector2f(410.f, 0.f), sf::Vector2f(20.f, 20.f));
		poles[1]->setName("factory");
		machineArray = d["factory"]["machines"];
		loadMachineArray(machineArray, poles[1]);

		// Pole garage
		poles[2] = new Grid(20, 20, sf::Vector2f(0.f, 410.f), sf::Vector2f(20.f, 20.f));
		poles[2]->setName("garage");
		machineArray = d["garage"]["machines"];
		loadMachineArray(machineArray, poles[2]);

		// Pole energy
		poles[3] = new Grid(20, 20, sf::Vector2f(410.f, 410.f), sf::Vector2f(20.f, 20.f));
		poles[3]->setName("energy");
		machineArray = d["energy"]["machines"];
		loadMachineArray(machineArray, poles[3]);
	}

	void loadMachineArray(rapidjson::Value& machineArray, Grid* pole)
	{
		for (rapidjson::SizeType i = 0; i < machineArray.Size(); i++)
		{
			std::string str = MACHINE_PATH;
			str.append(machineArray[i]["machine"].GetString());
			str.append(".json");
			Machine* m = loadMachine(str);
			m->setName(machineArray[i]["machine"].GetString());
			m->setPosition(sf::Vector2i(machineArray[i]["x"].GetInt(), machineArray[i]["y"].GetInt()));
			pole->addMachine(m);
		}
	}

	void loadItems(std::string JSonFile)
	{
		rapidjson::Document d = getDocument(JSonFile);

		rapidjson::Value& itemsArray = d["items"];
		for (rapidjson::SizeType i = 0; i < itemsArray.Size(); i++)
			new Item(itemsArray[i]["name"].GetString(), itemsArray[i]["class"].GetString(), itemsArray[i]["texture"].GetString());
	}
}