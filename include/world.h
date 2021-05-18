#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include <vector>

class World {
 public:
  static std::vector<Entity*> getEntities() { return entities_; }

  static void addEntity(Entity* entity) { entities_.push_back(entity); }

 private:
  static inline std::vector<Entity*> entities_;
};

#endif  // WORLD_H