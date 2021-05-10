#include "gui/profiler_gui.h"

#include <imgui.h>

ProfilerGui::ProfilerGui(const char* name) : AbstractGui(name) {}

void ProfilerGui::update() {
  ImGui::Begin(name_);

  for (const auto& profiler : Profiler::profilers()) {
    ImGui::Text("%s : %i ms\n", profiler.first, profiler.second);
  }

  ImGui::End();

  // if (ImGui::BeginMainMenuBar()) {
  //   if (ImGui::BeginMenu("Edit")) {
  //     if (ImGui::MenuItem("Undo", "CTRL+Z")) {
  //     }
  //     if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {
  //     }  // Disabled item
  //     ImGui::Separator();
  //     if (ImGui::MenuItem("Cut", "CTRL+X")) {
  //     }
  //     if (ImGui::MenuItem("Copy", "CTRL+C")) {
  //     }
  //     if (ImGui::MenuItem("Paste", "CTRL+V")) {
  //     }
  //     ImGui::EndMenu();
  //   }
  //   ImGui::EndMainMenuBar();
  // }
}