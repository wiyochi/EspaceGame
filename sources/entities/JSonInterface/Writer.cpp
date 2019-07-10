#include "Writer.hpp"

namespace Writer
{
    void save(std::string JSonFile, Grid* poles[4])
    {
        std::ofstream file(JSonFile, std::ios::out);
		std::string str;
        rapidjson::StringBuffer s;
        rapidjson::Writer<rapidjson::StringBuffer> writer(s);

		if (file)
		{
            writer.StartObject();

            for (size_t i = 0; i < 4; i++)
            {
                if(poles[i])
                {
                    writer.Key(poles[i]->getName().c_str());
                    writer.StartObject();

                    writer.Key("machines");
                    writer.StartArray();
                    for (const auto machine : poles[i]->getMachines())
                    {
                        writer.StartObject();
                        writer.Key("machine");
                        writer.String(machine->getName().c_str());
                        writer.Key("x");
                        writer.Int(machine->getPosition().x);
                        writer.Key("y");
                        writer.Int(machine->getPosition().y);
                        writer.EndObject();
                    }
                    writer.EndArray();

                    writer.EndObject();
                }
            }
            
            writer.EndObject();

            file << s.GetString();

			file.close();
        }
		else
		{
			std::cout << "Erreur save file" << std::endl;
		}        
    }
}