#pragma once
#include "IObject.h"
#include "Sprite.h"
class Shadow :
	public IObject
{
public:
	CSprite *sprite;

	Shadow();
	~Shadow();

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};

