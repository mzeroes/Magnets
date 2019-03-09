#pragma once

#ifdef MG_PLATFORM_WINDOWS

extern Magnets::Application *Magnets::CreateApplication();

int main(int argc, char **argv) {
  Magnets::Log::Init();

  MG_CORE_INFO("Starting application");

  auto app = Magnets::CreateApplication();
  app->run();

  delete app;
}
#endif  // MG_PLATFORM_WINDOWS
