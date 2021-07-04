#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include "Event.h"

namespace MyGameEngine
{

	class MYENGINE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(int pos_x, int pos_y)
			: m_PosX(pos_x), m_PosY(pos_y) {}

		inline float GetX() { return m_PosX; }
		inline float GetY() { return m_PosY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: ( " << m_PosX << "," << m_PosY << " )";
			return ss.str();
		}
		EVENT_CLASS_TYPE(MOUSE_HAS_MOVED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_INPUT | EVENT_CATEGORY_MOUSE)

	private:
		float m_PosX, m_PosY;
	};


	class MYENGINE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(int OffsetX, int OffsetY)
			: m_OffsetPosX(OffsetX), m_OffsetPosY(OffsetY) {}

		inline float GetOffsetPosX() { return m_OffsetPosX; }
		inline float GetOffsetPosY() { return m_OffsetPosY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: ( " << m_OffsetPosX << "," << m_OffsetPosY << " )";
			return ss.str();
		}
		EVENT_CLASS_TYPE(MOUSE_SCROLLED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_INPUT | EVENT_CATEGORY_MOUSE)

	private:
		float m_OffsetPosX, m_OffsetPosY;
	};


	class MYENGINE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() { return m_Button; }
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_INPUT | EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_MOUSE_BUTTON)

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class MYENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
	};

	class MYENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
	};
}


#endif