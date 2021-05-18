#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

#include "texture_manager.h"

class Player : public Entity {
 public:
  Player() {
    sf::Texture* tex = TextureManager::getTexture("megaman");
    sprite_.setTexture(*tex);
  }

 private:
  void drawCurrent(sf::RenderTarget& target,
                   sf::RenderStates states) const override {
    // states.transform = states.transform * getTransform();
    target.draw(sprite_, states);
  }

  sf::Sprite sprite_;
};

#endif  // PLAYER_H