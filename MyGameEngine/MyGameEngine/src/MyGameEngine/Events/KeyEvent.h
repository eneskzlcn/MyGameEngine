#ifndef KEY_EVENT_H
#define	KEY_EVENT_H

#include "Event.h"

namespace MyGameEngine
{

	class MYENGINE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return k_KeyCode; }
		
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_KEYBOARD | EVENT_CATEGORY_INPUT)

	protected:
		KeyEvent(int keyCode)
			: k_KeyCode(keyCode) {}

		int k_KeyCode;
	};

	class MYENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			:KeyEvent(keyCode), k_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return k_RepeatCount; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent:  " << k_KeyCode << " key " << k_RepeatCount << "  repeats";
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(KEY_PRESSED)

	private:
		int k_RepeatCount;
	};
	
	class MYENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent:  " << k_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KEY_RELEASED)
	};
}


#endif