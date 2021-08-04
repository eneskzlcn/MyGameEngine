#include "myengpch.h"

#include "WindowsWindow.h"
#include "MyGameEngine/Events/ApplicationEvent.h"
#include "MyGameEngine/Events/KeyEvent.h"
#include "MyGameEngine/Events/MouseEvent.h"


namespace MyGameEngine
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		MYENG_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}
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
		m_Data.Height = properties.Height;
		m_Data.Width = properties.Width;

		MYENG_CORE_INFO("Creating window {0} ({1},{2})", properties.Title, properties.Width, properties.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			MYENG_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height, properties.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//set glfw callbacks
		//
		//window resizing event callback
		glfwSetWindowSizeCallback(m_Window, 
			[](GLFWwindow* window, int width, int height)
		{
			WindowData& data = * (WindowData *)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;
			
			WindowResizedEvent event(width, height);
			data.EventCallback(event);
		});

		//window closing event callback
		glfwSetWindowCloseCallback(m_Window,
			[](GLFWwindow * window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowClosedEvent event;
				data.EventCallback(event);
			});

		// key callbacks...

		glfwSetKeyCallback(m_Window, 
			[](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}
				}
			});

		//mouse button callbacks...

		glfwSetMouseButtonCallback(m_Window,
			[](GLFWwindow* window,int button ,int action, int mods) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
			});

		//mouse scroll callbacks
		glfwSetScrollCallback(m_Window,
			[](GLFWwindow * window,double x_Offset, double y_Offset) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)(x_Offset), (float)(y_Offset));
				data.EventCallback(event);
			});
		//mouse move events
		glfwSetCursorPosCallback(m_Window,
			[](GLFWwindow * window, double xPos, double yPos) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)(xPos), (float)(yPos));
				data.EventCallback(event);
			});

	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

}

