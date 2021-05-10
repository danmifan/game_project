#ifndef GAME_H
#define GAME_H

#include "engine.h"

class Game {
 public:
  static float FPS() { return 1.0f / delta_time_; }
  static float deltaTime() { return delta_time_; }
  static int width() { return width_; }
  static int height() { return height_; }

 private:
  static void setDeltaTime(float delta_time) { delta_time_ = delta_time; }
  static void setWidth(uint width) { width_ = width; }
  static void setHeight(uint height) { height_ = height; }
  static inline float delta_time_ = 0.0f;
  static inline uint width_ = 0;
  static inline uint height_ = 0;

  friend class Engine;
};

#endif  // GAME_H