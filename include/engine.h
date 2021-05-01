#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

class Engine {
 public:
  Engine(uint width, uint height);
  void init();
  void update();
  void shutdown();

 private:
  sf::RenderWindow* window_;
};

#endif  // ENGINE_H