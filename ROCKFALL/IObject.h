#pragma once
#include <d3dx9.h>

class IObject
{

public:
	D3DXMATRIX mat;
	D3DXVECTOR2 pos, scale, rotationCenter, scalingCenter;
	float rot;
	bool isDelete;

	IObject();
	virtual ~IObject();

	virtual void Update(float eTime) = 0;
	virtual void Render(D3DXMATRIX *pmat);
};
