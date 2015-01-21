#include <windows.h>
#include "../hge181/include/hge.h"

// Lib 库的链接路径是以工程为相对路径进行查找的
#pragma comment(lib, "../Source/hge181/lib/vc/hge.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	HGE *pHGE = hgeCreate(HGE_VERSION);

	return 0;
}
