#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {
 public:
  // oof
  Entity();
  Entity(uint32_t id, std::string name);
  virtual ~Entity() {}

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void addChild(Entity* entity);
  void deleteChild(Entity* entity);

 protected:
  virtual void drawCurrent(sf::RenderTarget& target,
                           sf::RenderStates states) const = 0;

 private:
  uint32_t id_;
  std::string name_;

  std::vector<Entity*> children_;
  Entity* parent_;

  static inline int base_id_ = 0;
};

#endif  // ENTITY_H