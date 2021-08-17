#include "myengpch.h"
#include "Application.h"

#include "MyGameEngine\Events\KeyEvent.h"
#include "MyGameEngine\Events\Event.h"
#include "MyGameEngine\Events\MouseEvent.h"
#include "Log.h"
#include <glad/glad.h>

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
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClosed));
		MYENG_CORE_INFO("{0}",e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled)
				break;
		}
	}


	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	bool Application::OnWindowClosed(WindowClosedEvent& e)
	{
		IsAppRunning = false;
		return true;
	}
}



