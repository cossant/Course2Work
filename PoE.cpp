#include "start-form.h"
#include <Windows.h>

using namespace HotelInfoSystem;

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew startform);
    return 0;
}


