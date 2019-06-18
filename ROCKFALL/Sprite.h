#pragma once
#include "IObject.h"

typedef LPDIRECT3DTEXTURE9 LPTEXT;

class CSprite :
	public IObject
{
public:
	LPTEXT pTexture;
	int width, height;
	int opacity, red, green, blue;
	bool blendMode;
	RECT rect;
	CSprite(const char *path);			
	~CSprite();
	
	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};

