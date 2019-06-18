
#include "Enemy.h"
#include "Def.h"

Enemy::Enemy(int x, int y) :IObject()
{
	shadow = new Shadow();

	pos.x = x;
	pos.y = y;

	isEnemy = true;

	deleteTimer = new Timer(0.2f);

	breakCnt = 0;
}


Enemy::~Enemy()
{
	delete sprite;
	delete shadow;
	delete deleteTimer;
}

void Enemy::Update(float eTime)
{
	Attack(eTime);
	if (!isEnemy) {
		OnEnemyFalse(eTime);
		moveSpeed = 0.f;
	}
}

void Enemy::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	shadow->Render(0);
	sprite->Render(&mat);
}

