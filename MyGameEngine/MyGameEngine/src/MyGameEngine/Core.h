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

#define BIT(x)  ( 1 << x ) 