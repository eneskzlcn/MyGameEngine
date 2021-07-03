#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define	MYENGINE_API __declspec(dllexport)
	#else
		#define MYENGINE_API __declspec(dllimport)
	#endif
#else
	#error MyGameEngine only supports windows!
#endif

#define BIT(x)  ( 1 << x ) 