#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include <SFML/Window/Event.hpp>

class InputSystem {
 public:
  static void update(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
      switch (event.key.code) {
        case sf::Keyboard::Left:
          move_left_ = true;
          break;

        case sf::Keyboard::Right:
          move_right_ = true;
          break;

        case sf::Keyboard::Up:
          move_up_ = true;
          break;

        case sf::Keyboard::Down:
          move_down_ = true;
          break;

        default:
          break;
      }
    }
  }

  static void reset() {
    move_left_ = false;
    move_right_ = false;
    move_up_ = false;
    move_down_ = false;
  }

  static inline bool move_left_ = false;
  static inline bool move_right_ = false;
  static inline bool move_up_ = false;
  static inline bool move_down_ = false;

 private:
};

#endif  // INPUT_SYSTEM_H