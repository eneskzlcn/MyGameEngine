#pragma once

#ifdef MYENG_PLATFORM_WINDOWS
	#ifdef MYENG_BUILD_DLL
		#define	MYENGINE_API __declspec(dllexport)
	#else
		#define MYENGINE_API __declspec(dllimport)
	#endif
#else
	#error MyGameEngine only supports windows!
#endif

#ifdef MYENG_ENABLE_ASSERTS
	#define MYENG_ASSERT(x,...){if(!(x)) {MYENG_ERROR("Assertion failed: {0}",__VA_ARGS__); __debugbreak();}} 
	#define MYENG_CORE_ASSERT(x,...){if(!(x)) {MYENG_CORE_ERROR("Assertion failed: {0}",__VA_ARGS__); __debugbreak();}} 
#else
	#define MYENG_ASSERT(x,...);
	#define MYENG_CORE_ASSERT(x,...);
#endif

#define BIT(x)  ( 1 << x ) 