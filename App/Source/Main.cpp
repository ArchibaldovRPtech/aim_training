#include "Core/Application.h"

#include "AppLayer.h"

int main()
{
	Core::ApplicationSpecification appSpec;
	appSpec.Name = "Architecture";
	appSpec.WindowSpec.Width = 600;
	appSpec.WindowSpec.Height = 400;

	Core::Application application(appSpec);
	application.PushLayer<AppLayer>();
	application.Run();
}
