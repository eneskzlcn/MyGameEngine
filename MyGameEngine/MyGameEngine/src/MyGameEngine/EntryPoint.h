#pragma once

#ifdef HZ_PLATFORM_WINDOWS

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