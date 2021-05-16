#include "gui/test_gui.h"

#include "game.h"

TestGui::TestGui(const char* name) : AbstractGui(name) {}

void TestGui::update() {
  ImGuiWindowFlags window_flags =
      ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
      ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing |
      ImGuiWindowFlags_NoNav;

  if (ImGui::Begin("Example: Simple overlay", NULL, window_flags)) {
    ImGui::Text("Info\n");
    ImGui::Separator();
    ImGui::Text("FPS : %f\n", Game::FPS());
    ImGui::Text("Resolution : %i*%i\n", Game::width(), Game::height());
    ImGui::Text("Mouse x : %i y : %i\n", Game::mouseX(), Game::mouseY());
  }
  ImGui::End();
}