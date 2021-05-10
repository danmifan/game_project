#ifndef TEST_GUI_H
#define TEST_GUI_H

#include <gui/abstract_gui.h>
#include <imgui.h>

class TestGui : public AbstractGui {
 public:
  TestGui(const char* name) : AbstractGui(name) {}
  void update() override {
    ImGui::Begin(name_);

    ImGui::Button("test");

    ImGui::End();
  }

 private:
};

#endif  // TEST_GUI_H