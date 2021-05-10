#ifndef PROFILER_GUI_H
#define PROFILER_GUI_H

#include <gui/abstract_gui.h>
#include <profiler.h>

class ProfilerGui : public AbstractGui {
 public:
  ProfilerGui(const char* name);
  void update() override;

 private:
};

#endif  // PROFILER_GUI_H