#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "event_manager.h"
#include "move_event.h"

class MovementSystem {
 public:
  void init() {
    EventManager::subscribe(this, []() {

    });
  }

 private:
  void onEvent() {}
};

#endif  // MOVEMENT_SYSTEM_H