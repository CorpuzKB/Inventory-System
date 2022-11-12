
#include "Login.h"
#include "FrontForm.h"
#include <iostream>
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace InventorySystem;


[STAThreadAttribute]



int main()
{
	if (File::Exists(Application::StartupPath + "\\InventorySystem.exe.config")) {
		Login^ init = gcnew Login(Application::StartupPath);
		init->ShowDialog();
	}
	else {
		FrontForm^ init = gcnew FrontForm();
		init->ShowDialog();
	}
	return 0;

}