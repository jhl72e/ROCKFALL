#include "WinFrame.h"


HINSTANCE g_Inst;
HWND g_hWnd;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	srand((unsigned)GetTickCount());
	g_Inst = hInstance;
	InitWindow(hInstance, nCmdShow);
	HWND h = g_hWnd = FloatWindow(hInstance, nCmdShow);
	InitD3D(h);	
	return DoMainLoop();
}