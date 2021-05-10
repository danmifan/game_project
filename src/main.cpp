#include <iostream>

#include "engine.h"

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;

int main(int argc, char* argv[]) {
  Engine engine(WIDTH, HEIGHT);
  engine.init();
  // update is a blocking loop call
  engine.update();
  std::cout << "Bye !" << std::endl;
  return 0;
}
