#ifndef PROFILER_H
#define PROFILER_H

#include <chrono>
#include <iostream>

#include <map>

class Profiler {
 public:
  static void begin(const char* name) {
    start_ = std::chrono::high_resolution_clock::now();
    name_ = name;
  }

  static int end() {
    auto total = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - start_);
    auto it = profilers_.find(name_);
    if (it == profilers_.end()) {
      profilers_.insert(std::pair<const char*, int>(name_, total.count()));
    } else {
      profilers_[name_] = total.count();
    }
    return total.count();
  }

  static std::map<const char*, int> profilers() { return profilers_; }

 private:
  static inline std::chrono::high_resolution_clock clock_;
  static inline std::chrono::high_resolution_clock::time_point start_;
  static inline const char* name_;
  static inline std::map<const char*, int> profilers_;
};

#endif  // PROFILER_H