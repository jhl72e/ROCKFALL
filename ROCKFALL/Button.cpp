#include "Button.h"
#include "myFunction.h"

Button::Button(const char *path, int x, int y) : IObject()
{
	sprite = new CSprite(path);
	pos.x = x;
	pos.y = y;
}


Button::~Button()
{
	delete sprite;

}

void Button::Update(float eTime)
{
	
}

void Button::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	sprite->Render(&mat);  //&(this->mat)
}

bool Button::CheckMouse()
{
	if (MyGetCursorPos().y >= pos.y&&
		MyGetCursorPos().y <= pos.y + sprite->height&&
		MyGetCursorPos().x >= pos.x &&
		MyGetCursorPos().x <= pos.x + sprite->width)
	{
		return true;
	}
	return false;
}
