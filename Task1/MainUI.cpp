#include "MainUI.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Nếu MainUI nằm trong namespace Task1
    Application::Run(gcnew Task1::MainUI());

    // Nếu MainUI không có namespace, thì dùng:
    // Application::Run(gcnew MainUI());

    return 0;
}
