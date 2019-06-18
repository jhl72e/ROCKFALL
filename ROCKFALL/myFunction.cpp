#include <map>
#include "myFunction.h"
#include "GameScene.h"
#include "SoundMgr.h"

using namespace std;

extern LPDIRECT3DDEVICE9 g_pd3dDevice;
extern LPD3DXSPRITE g_pSprite;
extern HWND g_hWnd;
SoundMgr *soundMgr;

IScene *nowScene;
map<const char*, LPDIRECT3DTEXTURE9> texMap;

LARGE_INTEGER LInterval, RInterval, Frequency;
bool lkey[256], rkey[256];


LPDIRECT3DTEXTURE9 LoadTexture(const char* path) {
	if (texMap[path] != NULL) return texMap[path];
	D3DXCreateTextureFromFileExA(
		g_pd3dDevice,
		path,
		D3DX_DEFAULT_NONPOW2,	
		D3DX_DEFAULT_NONPOW2,
		1,	//¹Ó·¹º§¼ö
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,		
		D3DX_DEFAULT,
		RGB(255, 0, 255),		
		NULL,
		NULL,
		&texMap[path]);
	return texMap[path];
}

void Init(){
	soundMgr = new SoundMgr();
	nowScene = new TitleScene();
	QueryPerformanceCounter(&LInterval);
	QueryPerformanceFrequency(&Frequency);
	for (int i = 0; i < 256; i++){
		rkey[i] = lkey[i] = false;
	}
}

void Update(float eTime){
	if (eTime > 0.5f){
		return;
	}
	UpdateKeyState();
	nowScene->Update(eTime);
	soundMgr->Update();
}

void Render(){
	nowScene->Render();
}

void Destroy(){
	delete nowScene;
	map<const char*, LPDIRECT3DTEXTURE9>::iterator iter;
	for (iter = texMap.begin(); iter != texMap.end(); iter++){
		iter->second->Release();
	}
	delete soundMgr;
}

float GetElapsedTime(){
	QueryPerformanceCounter(&RInterval);
	__int64 Interval = (RInterval.QuadPart - LInterval.QuadPart);
	float eTime = (double)Interval / (double)Frequency.QuadPart;
	LInterval = RInterval;
	return eTime;
}

void UpdateKeyState(){
	for (int i = 0; i < 256; i++){
		lkey[i] = rkey[i];
		rkey[i] = GetKeyState(i) & 0x8000;
	}
}

int MyKeyState(int key){
	if (lkey[key] && rkey[key]){
		return 2;
	}
	if (!lkey[key] && rkey[key]){
		return 1;
	}
	if (lkey[key] && !rkey[key]){
		return -1;
	}
	return 0;
}


D3DXVECTOR2 MyGetCursorPos(){
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	D3DXVECTOR2 vector(float(pt.x), float(pt.y));
	return vector;
}



float GetDistance(D3DXVECTOR2 v1, D3DXVECTOR2 v2)
{
	return sqrt(pow(v1.x - v2.x,2)+pow(v1.y - v2.y,2));
}


void ChangeScene(IScene *newScene)
{
	delete nowScene;
	nowScene = newScene;
}