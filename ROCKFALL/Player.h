#pragma once
#include "IObject.h"
#include "Sprite.h"
#include "Timer.h"
#include "Shadow.h"

class Player :
	public IObject
{
public:
	Timer *animationTimer;
	CSprite *sprite;
	Shadow *shadow;
	float verMoveSpeed;
	float horMoveSpeed;
	int spriteIndex;

	Player();
	~Player();

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);

	void Move(float eTime);
	void SpriteUpdate(float eTime);
};