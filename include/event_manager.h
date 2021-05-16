#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <event.h>
#include <functional>
#include <list>
#include <typeindex>
#include <map>

class EventHandlerBase {
 public:
  void virtual call(Event* event) = 0;
};

template <class T, class EventType>
class EventHandler : public EventHandlerBase {
 public:
  EventHandler(T* instance, void (T::*function)()) {
    instance_ = instance;
    function_ = function;
  }

  void call(Event* event) override { (instance_->*function_)(); }

 private:
  T* instance_;
  void (T::*function_)();
};

class EventManager {
 public:
  template <class EventType>
  static void publish(EventType* event) {
    auto it = handler_map_.find(typeid(event));
    if (it != handler_map_.end()) {
      std::list<EventHandlerBase*> handlers = it->second;
      for (const auto& handler : handlers) {
        handler->call(event);
      }
    }
  }

  template <class T, class EventType>
  static void subscribe(T* instance, void (T::*function)()) {
    EventHandler<T, EventType> handler = new EventHandler<T, EventType>();

    if (handler_map_.find(typeid(EventType)) == handler_map_.end()) {
      std::list<EventHandlerBase*> handlers;
      handlers.push_back(handler);

      handler_map_.insert(
          std::pair<std::type_index, std::list<EventHandlerBase*>>(
              typeid(EventType), handlers));
    }
  }

 private:
  static inline std::map<std::type_index, std::list<EventHandlerBase*>>
      handler_map_;
};

#endif  // EVENT_MANAGER_H