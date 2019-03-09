#include <Magnets.h>
#include <stdio.h>
class Sandbox : public Magnets::Application {
 public:
  Sandbox() { MG_CORE_INFO("Started Sandbox Container"); }
  ~Sandbox() { MG_CORE_INFO("Destructing Sandbox Container"); }
};

Magnets::Application *Magnets::CreateApplication() { return new Sandbox; }
