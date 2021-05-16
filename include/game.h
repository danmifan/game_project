#ifndef GAME_H
#define GAME_H

#include "engine.h"

class Game {
 public:
  static float FPS() { return 1.0f / delta_time_; }
  static float deltaTime() { return delta_time_; }
  static int width() { return width_; }
  static int height() { return height_; }
  static int mouseX() { return mouse_x_; }
  static int mouseY() { return mouse_y_; }

 private:
  static void setDeltaTime(float delta_time) { delta_time_ = delta_time; }
  static void setWidth(uint width) { width_ = width; }
  static void setHeight(uint height) { height_ = height; }
  static void setMouseX(int x) { mouse_x_ = x; }
  static void setMouseY(int y) { mouse_y_ = y; }
  static inline float delta_time_ = 0.0f;
  static inline uint width_ = 0;
  static inline uint height_ = 0;
  static inline int mouse_x_ = 0;
  static inline int mouse_y_ = 0;

  friend class Engine;
};

#endif  // GAME_H