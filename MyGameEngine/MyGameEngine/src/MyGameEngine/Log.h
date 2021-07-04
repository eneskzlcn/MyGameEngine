#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog\fmt\ostr.h"

//This is a simple logging system for game engine that has the both logger for engine inside and client.
namespace MyGameEngine
{
	class MYENGINE_API Log
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
//-----------------------------------------------------------------------------------------

// Core Log Macros

#define MYENG_CORE_ERROR(...)		::MyGameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MYENG_CORE_INFO(...)		::MyGameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MYENG_CORE_TRACE(...)		::MyGameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MYENG_CORE_WARN(...)		::MyGameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MYENG_CORE_FATAL(...)		::MyGameEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros

#define MYENG_ERROR(...)			::MyGameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define MYENG_INFO(...)				::MyGameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define MYENG_TRACE(...)			::MyGameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MYENG_WARN(...)				::MyGameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MYENG_FATAL(...)			::MyGameEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
