#pragma once

#ifdef MYENG_PLATFORM_WINDOWS
//start point of application. This must be in the game engine side. Run the application is controlling from here.

extern MyGameEngine::Application* MyGameEngine::CreateApplication();
int main(int argc, char ** argv)
{
	MyGameEngine::Log::Init();
	MYENG_CORE_WARN("Initialized");
	MYENG_INFO("Hello!");
	auto app = MyGameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif