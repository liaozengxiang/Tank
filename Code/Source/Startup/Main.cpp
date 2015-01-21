#include <windows.h>
#include "../Application/Application.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	theApp.Initialize();
	theApp.Start();

	return 0;
}
