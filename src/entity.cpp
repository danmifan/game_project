#include "entity.h"

#include "world.h"

#include <iostream>

Entity::Entity() {
  name_ = "entity";
  id_ = base_id_;
  ++base_id_;

  // World::addEntity(this);
}

Entity::Entity(uint32_t id, std::string name) {
  id_ = id;
  name_ = name;
  parent_ = nullptr;

  // World::addEntity(this);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform = states.transform * getTransform();

  drawCurrent(target, states);

  for (const auto& child : children_) {
    target.draw(*child, states);
  }
}

void Entity::addChild(Entity* entity) {
  entity->parent_ = this;
  children_.push_back(entity);
}

void Entity::deleteChild(Entity* entity) {
  auto it = std::find_if(children_.begin(), children_.end(),
                         [=](Entity* current) { return current == entity; });
  if (it != children_.end()) {
    (*it)->parent_ = nullptr;
    children_.erase(it);
  }
}
