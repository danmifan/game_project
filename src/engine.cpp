#include "engine.h"

#include <imgui-SFML.h>
#include <imgui.h>

#include <iostream>

Engine::Engine(uint width, uint height) {
  window_ = new sf::RenderWindow(sf::VideoMode(width, height), "MyWindow");

  window_->setFramerateLimit(60);

  test_gui = new TestGui("MyWindow");
  addUI(test_gui);
}

void Engine::init() { ImGui::SFML::Init(*window_); }

void Engine::processEvents() {
  sf::Event event;
  while (window_->pollEvent(event)) {
    ImGui::SFML::ProcessEvent(event);
    // Event handling

    if (event.type == sf::Event::Closed) {
      active_ = false;
    }

    if (event.key.code == sf::Keyboard::Escape) {
      active_ = false;
    }
  }
}

void Engine::updateLogic() {}

void Engine::draw() {
  window_->clear(sf::Color::Black);

  // window_->draw(shape);

  drawUI();

  window_->display();
}

void Engine::drawUI() {
  elapsed_time_ = clock_.restart();
  ImGui::SFML::Update(*window_, elapsed_time_);

  for (const auto& gui : gui_) {
    gui->update();
  }

  ImGui::EndFrame();

  ImGui::SFML::Render(*window_);
}

void Engine::addUI(AbstractGui* gui) { gui_.push_back(gui); }

void Engine::update() {
  sf::Clock clock;
  while (active_) {
    elapsed_time_ = clock.restart();

    processEvents();
    updateLogic();
    draw();

    std::cout << "Elapsed time : " << elapsed_time_.asSeconds() << std::endl;
    std::cout << "FPS : " << 1.0f / elapsed_time_.asSeconds() << std::endl;
  }

  shutdown();
}

void Engine::shutdown() {
  std::cout << "Engine is shutting down..." << std::endl;
  window_->close();
  ImGui::SFML::Shutdown();
  delete window_;
}