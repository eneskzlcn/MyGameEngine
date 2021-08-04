#include "myengpch.h"
#include "Application.h"

#include "MyGameEngine\Events\KeyEvent.h"
#include "MyGameEngine\Events\Event.h"
#include "MyGameEngine\Events\ApplicationEvent.h"
#include "MyGameEngine\Events\MouseEvent.h"
#include "Log.h"

namespace MyGameEngine

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBackFunc(BIND_EVENT_FN(OnEvent));
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


	void Application::OnEvent(Event& e)
	{
		MYENG_CORE_INFO("{0}",e);
	}

}