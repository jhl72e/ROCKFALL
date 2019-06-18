#include "Shadow.h"
#include "myFunction.h"

Shadow::Shadow()
{
	sprite = new CSprite("images/Shadow.png");
	pos.x = WIDTH;
	pos.y = HEIGHT;
}

Shadow::~Shadow()
{
	delete sprite;
}

void Shadow::Update(float eTime) {
	sprite->Update(eTime);
}

void Shadow::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	sprite->Render(&(this->mat));
}
