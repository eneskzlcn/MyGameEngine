#include "Application.h"

#include "MyGameEngine\Events\KeyEvent.h"
#include "MyGameEngine\Events\Event.h"
#include "MyGameEngine\Events\ApplicationEvent.h"
#include "MyGameEngine\Events\MouseEvent.h"
#include "Log.h"

namespace MyGameEngine

{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		//defining one instance from all event kinds to try them by logging system if they works
		// without any other functions.
		//-- window events
		WindowResizedEvent wre(1200, 500);
		WindowClosedEvent wce;
		WindowFocusedEvent wfe;
		WindowFocusLostEvent wfle;
		// -- app events
		AppTickEvent ate;
		AppRenderEvent are;
		AppUpdateEvent aue;
		//--key events
		KeyPressedEvent kpe(20, 2);
		KeyReleasedEvent kre(10);
		//--mouse events
		MouseButtonPressedEvent mbpe(1);
		MouseButtonReleasedEvent mbre(0);
		MouseScrolledEvent mse(10, 20);
		MouseMovedEvent mme(20, 50);

		//window resize event is just in application event category, check for that...
		if (wre.IsInCategory(EventCategory::EVENT_CATEGORY_APP))
		{
			MYENG_CORE_WARN(wre);
		}
		//window closed event is just in application event category, check for that...
		if (wce.IsInCategory(EventCategory::EVENT_CATEGORY_APP))
		{
			MYENG_CORE_WARN(wce);
		}
		//window focused event is just in application event category, check for that...
		if (wfe.IsInCategory(EventCategory::EVENT_CATEGORY_APP))
		{
			MYENG_CORE_WARN(wfe);
		}
		//window focus lost event is just in application event category, check for that...
		if (wfle.IsInCategory(EventCategory::EVENT_CATEGORY_APP))
		{
			MYENG_CORE_WARN(wfle);
		}
		//application tick event is just in application event category, check for that...
		if (ate.IsInCategory(EventCategory::EVENT_CATEGORY_APP))
		{
			MYENG_CORE_WARN(ate);
		}
		//application render event is just in application event category, check for that...
		if (are.IsInCategory(EventCategory::EVENT_CATEGORY_APP))
		{
			MYENG_CORE_WARN(are);
		}
		//application update event is just in application event category, check for that...
		if (aue.IsInCategory(EventCategory::EVENT_CATEGORY_APP))
		{
			MYENG_CORE_WARN(aue);
		}
		// key pressed event is both in input and keyboard event category. check for that... ( will log 2 times for this event)
		if (kpe.IsInCategory(EventCategory::EVENT_CATEGORY_INPUT))
		{
			MYENG_CORE_WARN(kpe);
		}
		if (kpe.IsInCategory(EventCategory::EVENT_CATEGORY_KEYBOARD))
		{
			MYENG_CORE_WARN(kpe);
		}
		// key released event is both in input and keyboard event category. check for that... ( will log 2 times for this event)
		if (kre.IsInCategory(EventCategory::EVENT_CATEGORY_INPUT))
		{
			MYENG_CORE_WARN(kre);
		}
		if (kre.IsInCategory(EventCategory::EVENT_CATEGORY_KEYBOARD))
		{
			MYENG_CORE_WARN(kre);
		}
		//mouse button pressed event is in the event category of mouse, mouse_button and input. check for that(will log 3 times
		//for this event)
		if (mbpe.IsInCategory(EventCategory::EVENT_CATEGORY_MOUSE))
		{
			MYENG_CORE_WARN(mbpe);
		}
		if (mbpe.IsInCategory(EventCategory::EVENT_CATEGORY_MOUSE_BUTTON))
		{
			MYENG_CORE_WARN(mbpe);
		}
		if (mbpe.IsInCategory(EventCategory::EVENT_CATEGORY_INPUT))
		{
			MYENG_CORE_WARN(mbpe);
		}
		//mouse button released event is in the event category of mouse, mouse_button and input. check for that(will log 3 times
		//for this event)
		if (mbre.IsInCategory(EventCategory::EVENT_CATEGORY_MOUSE))
		{
			MYENG_CORE_WARN(mbre);
		}
		if (mbre.IsInCategory(EventCategory::EVENT_CATEGORY_MOUSE_BUTTON))
		{
			MYENG_CORE_WARN(mbre);
		}
		if (mbre.IsInCategory(EventCategory::EVENT_CATEGORY_INPUT))
		{
			MYENG_CORE_WARN(mbre);
		}
		//a mouse scrool event is in the event category of input and mouse, check for that...
		if (mse.IsInCategory(EventCategory::EVENT_CATEGORY_INPUT))
		{
			MYENG_CORE_WARN(mse);
		}
		if (mse.IsInCategory(EventCategory::EVENT_CATEGORY_MOUSE))
		{
			MYENG_CORE_WARN(mse);
		}
		//a mouse move event is in the event category of input and mouse, chech for that...
		if (mme.IsInCategory(EventCategory::EVENT_CATEGORY_INPUT))
		{
			MYENG_CORE_WARN(mme);
		}
		if (mme.IsInCategory(EventCategory::EVENT_CATEGORY_MOUSE))
		{
			MYENG_CORE_WARN(mme);
		}
		while (true);
	}


}