#include "EnemyA.h"


EnemyA::EnemyA(int x, int y) :Enemy(x,y)
{
	sprite = new CSprite("images/Stone/Stone1.png");
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;

	pos.y = y;
	pos.x = STARTPOS;

	moveSpeed = 400.f;
}

EnemyA::~EnemyA()
{

}

void EnemyA::Attack(float eTime)
{
	pos.x += moveSpeed * eTime;
	sprite->rot += 0.1;

	shadow->pos.x = pos.x;
	shadow->pos.y = pos.y + 60;
}

void EnemyA::OnEnemyFalse(float eTime) {
	deleteTimer->Update(eTime);
	switch (breakCnt) {
		case 0:
			sprite = new CSprite("images/Stone/Stone1_break1.png");
			break;
		case 1:
			sprite = new CSprite("images/Stone/Stone1_break2.png");
			break;
		case 2:
			sprite = new CSprite("images/Stone/Stone1_break3.png");
			break;
		case 3:
			isDelete = true;
			break;
	}
	if (deleteTimer->isDone) {
		breakCnt++;
	}
}