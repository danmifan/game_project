#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class TextureManager {
 public:
  static void loadTexture(std::string path, std::string name) {
    sf::Texture* texture = new sf::Texture();
    if (!texture->loadFromFile(path)) {
      std::cout << "[ERROR] Texture " << path << "could not be loaded"
                << std::endl;
    }
    textures_.insert(std::pair<std::string, sf::Texture*>(name, texture));
  }

  static sf::Texture* getTexture(std::string name) { return textures_[name]; }

 private:
  static inline std::map<std::string, sf::Texture*> textures_;
};

#endif  // TEXTURE_MANAGER_H