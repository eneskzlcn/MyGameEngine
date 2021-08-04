#pragma once

#include "MyGameEngine/Window.h"
#include <GLFW/glfw3.h>

namespace MyGameEngine
{
	class WindowsWindow : public Window
	{

	public:

		WindowsWindow(const WindowProperties& w_properties);
		virtual ~WindowsWindow();

		void OnUpdate() override;


		unsigned int GetWidth() { return m_Data.Width; }


		unsigned int GetHeight() { return m_Data.Height; }


		bool IsVSync() const override;


		void SetVSync(bool enabled) override;

		void SetEventCallBackFunc(const EventCallbackFunction& callback) override { m_Data.EventCallback = callback; }

	private:

		virtual void Init(const WindowProperties& properties);

		virtual void ShutDown();

	private:

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFunction EventCallback;
		};

		WindowData m_Data;
	};
}

