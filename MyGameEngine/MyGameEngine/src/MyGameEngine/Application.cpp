#include "myengpch.h"
#include "Application.h"

#include "MyGameEngine\Events\KeyEvent.h"
#include "MyGameEngine\Events\Event.h"
#include "MyGameEngine\Events\ApplicationEvent.h"
#include "MyGameEngine\Events\MouseEvent.h"
#include "Log.h"

namespace MyGameEngine

{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		
		while (IsAppRunning)
		{
			m_Window->OnUpdate();
		}
	}


}