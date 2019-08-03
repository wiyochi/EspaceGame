#ifndef _TEXTURE_MANAGER_
#define _TEXTURE_MANAGER_

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

namespace textureManager {

std::map<std::string, sf::Texture*> textures;
std::vector<std::string> order;

sf::Texture* loadTexture(std::string name, std::string path);
sf::Texture* getTexture(std::string name);
void freeTextureManager();

}  // namespace textureManager

#endif
