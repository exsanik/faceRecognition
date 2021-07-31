#include "Interface.h"
#include "Libs.h"

using namespace FaceRecognition;
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Interface());
	return 0;
}