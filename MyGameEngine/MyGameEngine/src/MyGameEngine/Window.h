#pragma once
#include "myengpch.h"
#include "MyGameEngine\Events\Event.h"
#include "MyGameEngine\Core.h";

namespace MyGameEngine
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProperties(const std::string & title = "My Game Engine",
			unsigned int width = 1280, unsigned int height = 720)
				:Title(title), Width(width), Height(height) {}
		
	};

	class MYENGINE_API Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;
		virtual ~Window(){}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() = 0;
		virtual unsigned int GetHeight() = 0;

		virtual bool IsVSync() const = 0;
		virtual void SetVSync(bool enabled) const = 0;
		virtual void SetEventCallBackFunc(const EventCallbackFunction& callback) = 0;

		static Window* Create(const WindowProperties& w_properties = WindowProperties());
	};

}