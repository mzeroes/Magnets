workspace "Magnets"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Magnets/vendor/GLFW/include"
include "Magnets/vendor/GLFW"

project "Magnets"
	location "Magnets"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mgpch.h"
	pchsource "Magnets/src/mgpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Magnets/src",
		"Magnets/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MG_PLATFORM_WINDOWS",
			"MG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MG_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MG_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "MG_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Magnets/vendor/spdlog/include",
		"Magnets/src"
	}
	
	links
	{
		"Magnets"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MG_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "MG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MG_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "MG_DIST"
		optimize "On"
