
#ifndef APPLICATION_EVENT_H
#define APPLICATION_EVENT_H

#include <sstream>
#include "Event.h"

namespace MyGameEngine
{

	class MYENGINE_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(unsigned int width, unsigned int height)
			: w_Width(width), w_Height(height) {}
		
		inline unsigned int GetWidth() const { return w_Width; }
		inline unsigned int GetHeight() const { return w_Height; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizedEvent:  (" << w_Width << ", " << w_Height << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(WINDOW_RESIZED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	private:
		unsigned int w_Width, w_Height;
	};

	class MYENGINE_API WindowClosedEvent : public Event
	{
	public:

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowClosedEvent: ";
			return ss.str();
		}
		EVENT_CLASS_TYPE(WINDOW_CLOSED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)

	};
	class MYENGINE_API WindowFocusedEvent : public Event
	{
	public:
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowFocusedEvent: ";
			return ss.str();
		}
		EVENT_CLASS_TYPE(WINDOW_FOCUSED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};
	class MYENGINE_API WindowFocusLostEvent : public Event
	{
	public:
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowFocusLostEvent: ";
			return ss.str();
		}
		EVENT_CLASS_TYPE(WINDOW_FOCUS_LOST)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};

	class MYENGINE_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int pos_x, int pos_y)
			: Pos_X(pos_x), Pos_Y(pos_y) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: " << "(" << Pos_X << "," << Pos_Y << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(WINDOW_MOVED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	private:
		int Pos_X, Pos_Y;

	};

	class MYENGINE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppTickEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(APP_TICK)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};

	class MYENGINE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(APP_UPDATE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};

	class MYENGINE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppRenderEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(APP_RENDER)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)
	};
}
#endif