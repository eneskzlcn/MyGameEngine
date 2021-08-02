#pragma once
#include "Core.h"
#include "Window.h"

namespace MyGameEngine
{
	class MYENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool IsAppRunning = true;
	};

	Application* CreateApplication();

}