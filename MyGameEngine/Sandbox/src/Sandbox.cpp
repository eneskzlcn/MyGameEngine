#include <MyGameEngine.h>

class ExampleLayer : public MyGameEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		MYENG_INFO("ExampleLayer::Update");
	}
	void OnEvent(MyGameEngine::Event & e)
	{
		MYENG_TRACE("{0}", e);
	}
};


class SandBox : public MyGameEngine::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}
	~SandBox()
	{

	}
};

MyGameEngine::Application* MyGameEngine::CreateApplication()
{
	return new SandBox();
}
