#pragma once
#include <Magnets/Core.h>

namespace Magnets {

class MAGNETS_API Application {
 public:
  Application();
  virtual ~Application();

  void run();
};
// TO BE DEFINED IN CLIENT
Application *CreateApplication();

}  // namespace Magnets
