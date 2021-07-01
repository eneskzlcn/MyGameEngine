#pragma once
#include "Core.h"

namespace MyGameEngine
{
	class MYENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}