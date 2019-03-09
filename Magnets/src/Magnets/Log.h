#pragma once

#include "mgpch.h"

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Magnets {
class MAGNETS_API Log {
 public:
  static void Init();
  inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
    return s_CoreLogger;
  }
  inline static std::shared_ptr<spdlog::logger> &GetClientLogger() {
    return s_ClientLogger;
  }

 private:
  static std::shared_ptr<spdlog::logger> s_CoreLogger;
  static std::shared_ptr<spdlog::logger> s_ClientLogger;
};
}  // namespace Magnets

// Logging API...

using Magnets::Log;

#define MG_CORE_INFO(...) Log::GetCoreLogger()->info(__VA_ARGS__)
#define MG_CORE_WARN(...) Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MG_CORE_ERROR(...) Log::GetCoreLogger()->error(__VA_ARGS__)
#define MG_CORE_TRACE(...) Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MG_CORE_FATAL(...) Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define MG_CLIENT_INFO(...) Log::GetClientLogger()->info(__VA_ARGS__)
#define MG_CLIENT_WARN(...) Log::GetClientLogger()->warn(__VA_ARGS__)
#define MG_CLIENT_ERROR(...) Log::GetClientLogger()->error(__VA_ARGS__)
#define MG_CLIENT_TRACE(...) Log::GetClientLogger()->trace(__VA_ARGS__)
#define MG_CLIENT_FATAL(...) Log::GetClientLogger()->fatal(__VA_ARGS__)
