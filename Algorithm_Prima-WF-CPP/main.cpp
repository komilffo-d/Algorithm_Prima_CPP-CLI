#include "pch.h"

using namespace System;

#include "Form.h"


using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew FormNamespace::Form());
  return 0;
}