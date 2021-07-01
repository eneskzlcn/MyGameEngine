#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern MyGameEngine::Application* MyGameEngine::CreateApplication();
int main(int argc, char ** argv)
{
	auto app = MyGameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif