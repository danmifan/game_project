#include <iostream>

#include "engine.h"
#include "world.h"
#include "texture_manager.h"
#include "player.h"
#include "move_system.h"

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;

int main(int argc, char* argv[]) {
  Engine engine(WIDTH, HEIGHT);
  engine.init();
  // update is a blocking loop call

  Player* player = new Player();

  player->setPosition(0.0f, 0.0f);
  // player->setRotation(45.0f);
  player->setScale(0.1f, 0.1f);

  Player* player2 = new Player();

  player->addChild(player2);
  player2->setPosition(1500.0f, 800.0f);

  World::addEntity(player);

  MoveSystem::setEntity(player);

  engine.update();
  std::cout << "Bye !" << std::endl;
  return 0;
}
