#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Magnets {
	class MAGNETS_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define MG_CORE_INFO(...)		::Magnets::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MG_CORE_WARN(...)		::Magnets::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MG_CORE_ERROR(...)		::Magnets::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MG_CORE_TRACE(...)		::Magnets::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MG_CORE_FATAL(...)		::Magnets::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define MG_CLIENT_INFO(...)		::Magnets::Log::GetClientLogger()->info(__VA_ARGS__)
#define MG_CLIENT_WARN(...)		::Magnets::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MG_CLIENT_ERROR(...)	::Magnets::Log::GetClientLogger()->error(__VA_ARGS__)
#define MG_CLIENT_TRACE(...)	::Magnets::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MG_CLIENT_FATAL(...)	::Magnets::Log::GetClientLogger()->fatal(__VA_ARGS__)