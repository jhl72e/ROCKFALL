#pragma once
#include "IObject.h"
#include "Sprite.h"
#include "Timer.h"
#include "Def.h"
#include "Shadow.h"
class Enemy :
	public IObject
{
public:
	CSprite *sprite;
	Shadow *shadow;

	Timer *deleteTimer;

	float moveSpeed;
	bool isEnemy;
	int breakCnt;

	Enemy(int x, int y);
	virtual	~Enemy();
	
	virtual void Update(float eTime);
	virtual void Attack(float eTime) = 0;

	void Render(D3DXMATRIX *pmat);

	virtual void OnEnemyFalse(float eTime) = 0;
};

