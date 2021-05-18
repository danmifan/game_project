#ifndef MOVE_SYSTEM_H
#define MOVE_SYSTEM_H

#include "input_system.h"
#include "game.h"
#include "entity.h"

class MoveSystem {
 public:
  void static update() {
    if (entity_) {
      sf::Vector2f position = entity_->getPosition();
      const float ifps = Game::deltaTime();
      if (InputSystem::move_left_) {
        position.x -= move_speed_ * ifps;
      }

      if (InputSystem::move_right_) {
        position.x += move_speed_ * ifps;
      }

      entity_->setPosition(position);
    }
  }

  void static setEntity(Entity* entity) { entity_ = entity; }

 private:
  static inline float move_speed_ = 100.0f;
  static inline Entity* entity_;
};

#endif  // MOVE_SYSTEM_H