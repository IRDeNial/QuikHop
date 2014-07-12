#include "MyForm.h"
#include <string>

using namespace QuikHop;

[STAThreadAttribute]
int main(array<System::String ^> ^args) {
   	Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false); 

   	Application::Run(gcnew MyForm());
	return 0;
}

