#include "engine.h"

#include <iostream>

Engine::Engine(uint width, uint height) {
  window_ = new sf::RenderWindow(sf::VideoMode(width, height), "MyWindow");
}

void Engine::init() {}

void Engine::update() {
  while (window_->isOpen()) {
    sf::Event event;
    while (window_->pollEvent(event)) {
      // Event handling

      if (event.key.code == sf::Keyboard::Escape) {
        window_->close();
      }
    }

    window_->clear(sf::Color::Black);

    // Draw here

    window_->display();
  }
}

void Engine::shutdown() {
  std::cout << "Engine is shutting down..." << std::endl;
}