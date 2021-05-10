#ifndef TEST_GUI_H
#define TEST_GUI_H

#include <gui/abstract_gui.h>
#include <imgui.h>

class TestGui : public AbstractGui {
 public:
  TestGui(const char* name);
  void update() override;

 private:
};

#endif  // TEST_GUI_H