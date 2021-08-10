#pragma once
#include "Core.h"
#include "Window.h"
#include "MyGameEngine/LayerStack.h"
#include "MyGameEngine/Events/ApplicationEvent.h"
namespace MyGameEngine
{
	class MYENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);

		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClosed(WindowClosedEvent& e);
		std::unique_ptr<Window> m_Window;
		bool IsAppRunning = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();

}