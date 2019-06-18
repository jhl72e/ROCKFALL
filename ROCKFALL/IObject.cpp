#include "IObject.h"


IObject::IObject()
{
	D3DXMatrixIdentity(&mat);
	pos = rotationCenter = scalingCenter = D3DXVECTOR2(0, 0);
	scale = D3DXVECTOR2(1, 1);
	rot = 0.f;
	isDelete = false;
}


IObject::~IObject()
{

}


void IObject::Update(float eTime)
{

}

void IObject::Render(D3DXMATRIX *pmat)
{
	D3DXMatrixTransformation2D(
		&mat,
		&scalingCenter,
		0.f,
		&scale,
		&rotationCenter,
		rot,
		&pos);

	if (pmat != NULL)
	{
		mat *= (*pmat);
	}
}
