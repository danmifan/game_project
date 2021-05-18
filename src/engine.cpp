#include "engine.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include <game.h>
#include <profiler.h>
#include <world.h>
#include <texture_manager.h>
#include "input_system.h"
#include "move_system.h"

#include <iostream>

Engine::Engine(uint width, uint height) {
  window_ = new sf::RenderWindow(sf::VideoMode(width, height), "MyWindow");

  Game::setHeight(height);
  Game::setWidth(width);

  window_->setFramerateLimit(60);

  test_gui_ = new TestGui("MyWindow");
  profiler_gui_ = new ProfilerGui("Profiler");
  addUI(test_gui_);
  addUI(profiler_gui_);
}

void Engine::init() {
  ImGui::SFML::Init(*window_);

  TextureManager::loadTexture("resources/textures/megaman.png", "megaman");
}

void Engine::processEvents() {
  sf::Event event;
  while (window_->pollEvent(event)) {
    ImGui::SFML::ProcessEvent(event);
    // Event handling

    if (event.type == sf::Event::Closed) {
      active_ = false;
    }

    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Escape) {
      active_ = false;
    }

    if (event.type == sf::Event::MouseMoved) {
      const sf::Vector2i mouse_coords = sf::Mouse::getPosition(*window_);
      Game::setMouseX(mouse_coords.x);
      Game::setMouseY(mouse_coords.y);
    }

    // Placeholder
    InputSystem::update(event);
  }
}

void Engine::updateLogic() {
  MoveSystem::update();
  InputSystem::reset();
}

void Engine::draw() {
  Profiler::begin("Drawing");
  window_->clear(sf::Color::Black);

  // Drawing all of our entities
  for (const auto& entity : World::getEntities()) {
    window_->draw(*entity);
  }

  drawUI();

  Profiler::end();

  window_->display();
}

void Engine::drawUI() {
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
    Game::setDeltaTime(elapsed_time_.asSeconds());

    Profiler::begin("Event processing");
    processEvents();
    Profiler::end();

    Profiler::begin("Update logic");
    updateLogic();
    Profiler::end();

    draw();
  }

  shutdown();
}

void Engine::shutdown() {
  std::cout << "Engine is shutting down..." << std::endl;
  window_->close();
  ImGui::SFML::Shutdown();
  delete window_;
}