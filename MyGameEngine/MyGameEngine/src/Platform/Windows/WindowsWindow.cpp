#include "myengpch.h"
#include "MyGameEngine/Log.h"
#include "WindowsWindow.h"


namespace MyGameEngine
{
	static bool s_GLFWInitialized = false;

	Window * Window::Create(const WindowProperties& w_properties)
	{
		return new WindowsWindow(w_properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& w_properties)
	{
		Init(w_properties);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);	

		m_Data.VSync = enabled;
	}

	void WindowsWindow::Init(const WindowProperties& properties)
	{
		m_Data.Title = properties.Title;
		m_Data.m_Height = properties.Height;
		m_Data.m_Width = properties.Width;

		MYENG_CORE_INFO("Creating window {0} ({1},{2})", properties.Title, properties.Width, properties.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			MYENG_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height, properties.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

}

