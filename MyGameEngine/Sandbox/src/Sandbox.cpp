#include <MyGameEngine.h>

class SandBox : public MyGameEngine::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

MyGameEngine::Application* MyGameEngine::CreateApplication()
{
	return new SandBox();
}
