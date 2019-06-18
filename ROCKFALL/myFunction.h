#pragma once
#include <windows.h>
#include <d3dx9.h>
#include "Def.h"
#include "IScene.h"
#include "TitleScene.h"

LPDIRECT3DTEXTURE9 LoadTexture(const char* path);

void Init();
void Update(float eTime);
void Render();
void Destroy();
float GetElapsedTime();
void UpdateKeyState();
int MyKeyState(int key);
D3DXVECTOR2 MyGetCursorPos();
float GetDistance(D3DXVECTOR2 v1, D3DXVECTOR2 v2);
void ChangeScene(IScene *newScene);