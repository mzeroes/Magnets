#pragma once

#ifdef MG_PLATFORM_WINDOWS

extern Magnets::Application* Magnets::CreateApplication();

#include <stdio.h>


int main(int argc, char** argv) {
	printf("Starting Application...");
	auto app = Magnets::CreateApplication();
	app->run();
	delete app;
	printf("Ending Application...");

}
#endif // MG_PLATFORM_WINDOWS
