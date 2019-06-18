#pragma once
#include <windows.h>
#include <d3dx9.h>

void InitWindow(HINSTANCE hInstance, int nCmdShow);
HWND FloatWindow(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

void InitD3D(HWND hWnd);

int DoMainLoop();