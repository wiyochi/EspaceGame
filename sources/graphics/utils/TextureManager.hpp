#ifndef _TEXTURE_MANAGER_
#define _TEXTURE_MANAGER_

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
public:
	TextureManager();
	sf::Texture* loadTexture(std::string name, std::string path);
	sf::Texture* getTexture(std::string name);
	~TextureManager();
private:
	static std::map<std::string, sf::Texture*> textures;
	static std::vector<std::string> order;
};

#endif
