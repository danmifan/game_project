#ifndef DUMMY_H
#define DUMMY_H

#include "entity.h"

class Dummy : public Entity {
 public:
  Dummy() {}

 private:
  void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) {
    target.draw(sprite_, states);
  }
  sf::Sprite sprite_;
};

#endif  // DUMMY_H