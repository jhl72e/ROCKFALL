#pragma once
#include "IObject.h"
#include "Sprite.h"
class Button :
	public IObject
{
public:
	CSprite *sprite;
	Button(const char *path, int x, int y);
	~Button();
	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
	bool CheckMouse();
};

