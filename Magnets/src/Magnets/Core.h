#pragma once
// basic macros
#ifdef MG_PLATFORM_WINDOWS
	#ifdef MG_BUILD_DLL
		#define MAGNETS_API __declspec(dllexport)
	#else
		#define MAGNETS_API __declspec(dllimport)
	#endif // MG_BUILD_DLL
#else
	#error ONLY WIN SUPPORTED
#endif // MG_PLATFORM_WINDOWS