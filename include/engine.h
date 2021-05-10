#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

#include <gui/abstract_gui.h>
#include <gui/test_gui.h>
#include <gui/profiler_gui.h>

#include <list>

class Engine {
 public:
  Engine(uint width, uint height);
  void init();
  void update();

  void addUI(AbstractGui* gui);

 private:
  void shutdown();
  void processEvents();
  void updateLogic();
  void draw();
  void drawUI();

  sf::RenderWindow* window_;
  sf::Time elapsed_time_;
  sf::Clock clock_;

  std::list<AbstractGui*> gui_;
  bool active_ = true;

  TestGui* test_gui_;
  ProfilerGui* profiler_gui_;
};

#endif  // ENGINE_H