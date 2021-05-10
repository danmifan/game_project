#include "gui/test_gui.h"

#include "game.h"

TestGui::TestGui(const char* name) : AbstractGui(name) {}

void TestGui::update() {
  ImGuiWindowFlags window_flags =
      ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
      ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing |
      ImGuiWindowFlags_NoNav;

  bool p_open;

  if (ImGui::Begin("Example: Simple overlay", &p_open, window_flags)) {
    ImGui::Text("Info\n");
    ImGui::Separator();
    ImGui::Text("FPS : %f\n", Game::FPS());
    ImGui::Text("Resolution : %i*%i\n", Game::width(), Game::height());
  }
  ImGui::End();
}