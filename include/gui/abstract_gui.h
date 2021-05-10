#ifndef ABSTRACT_GUI_H
#define ABSTRACT_GUI_H

class AbstractGui {
 public:
  AbstractGui(const char* name) { name_ = name; }
  ~AbstractGui();

  virtual void update() = 0;

 protected:
  const char* name_;
};

#endif  // ABSTRACT_GUI_H