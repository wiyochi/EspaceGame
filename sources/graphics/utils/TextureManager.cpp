#include "TextureManager.hpp"

TextureManager::TextureManager()
{
}

std::map<std::string, sf::Texture*> TextureManager::textures;
std::vector<std::string> TextureManager::order;

// Get Texture by Name
sf::Texture *TextureManager::getTexture(std::string name)
{

    // See if we have already loaded this texture
    if(textures.find(name) != textures.end()){
        return textures[name];
    } else {
        return NULL;
    }
}

// Assign a Texture a Name (for accessing via get) and path (to load from)
sf::Texture *TextureManager::loadTexture(std::string name, std::string path)
{
    // Haven't loaded it yet, time to create it
    sf::Texture *texture = new sf::Texture();

    if(texture->loadFromFile(path))
    {
        textures[name] = texture;

        // Push to vector the order in which items were loaded into map, for accessing via index.
        order.push_back(name);
        return textures[name];
    }
    else
    {
        // Could not load the file
        delete texture;
        return NULL;
    }

}

TextureManager::~TextureManager()
{

    // Delete all of the textures we used
    sf::Texture *texture;
    std::map<std::string, sf::Texture*>::iterator iter = textures.begin();
    while(iter != textures.end())
    {
        texture = iter->second;
        delete texture;
        iter++;
    }
}
