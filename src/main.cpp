#include <iostream>

#include "engine.h"

int main(int argc, char* argv[]) {
  Engine engine(1280, 720);
  engine.init();
  // update is a blocking loop call
  engine.update();
  engine.shutdown();
  std::cout << "Bye !" << std::endl;
  return 0;
}
