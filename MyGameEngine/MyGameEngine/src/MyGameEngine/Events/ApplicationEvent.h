
#include <sstream>
#include "Event.h"
namespace MyGameEngine
{

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(unsigned int width, unsigned int height)
		{
			: w_Width(width), w_Height(height) {}
		}

		inline unsigned int GetWidth() const { return w_Width; }
		inline unsigned int GetHeight() const { return w_Height; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizedEvent:  " << w_Width << ", " << w_Height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WINDOW_RESIZED)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APP)


	private:
		unsigned int w_Width, w_Height;
	};
}