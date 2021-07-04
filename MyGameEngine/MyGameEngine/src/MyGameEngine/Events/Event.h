#ifndef EVENT_H
#define EVENT_H

#include "MyGameEngine/Core.h"

namespace MyGameEngine
{
	enum class EventType
	{
		NONE = 0,
		WINDOW_CLOSED, WINDOW_RESIZED, WINDOW_FOCUSED, WINDOW_FOCUS_LOST, WINDOW_MOVED,
		APP_TICK, APP_UPDATE, APP_RENDER,
		KEY_PRESSED, KEY_RELEASED,
		MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_HAS_MOVED, MOUSE_SCROLLED
	};
	//For controlling the category of the events with bitmasks. 
	enum EventCategory
	{
		NONE = 0,
		EVENT_CATEGORY_APP = BIT(0),
		EVENT_CATEGORY_INPUT = BIT(1),
		EVENT_CATEGORY_KEYBOARD = BIT(2),
		EVENT_CATEGORY_MOUSE = BIT(3),
		EVENT_CATEGORY_MOUSE_BUTTON = BIT(4)
	};

	//  macros to make event class's - implement needed and class indepented functions easier and reusable.

	#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() {return EventType::##type;} \
									EventType GetEventType() const override {return GetStaticType();} \
									const char* GetName() const override { return #type;}

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category;}


	class MYENGINE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual const char* GetName() const = 0; // double const using means constant pointer to a constant variable
		virtual int GetCategoryFlags() const = 0;
		virtual EventType GetEventType() const = 0;
		virtual std::string ToString() const { return GetName(); }
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool IsHandled = false;
	};

	class EventDispatcher
	{
		template <typename T> // T which is the Event
		using EventFunction = std::function<bool(T&)>; // event callback functions should contain a event parameter and should return bool.
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template <typename T >
		bool Dispatch(EventFunction<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.IsHandled = func(*((T*)&m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator <<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}

#endif