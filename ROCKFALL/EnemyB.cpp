#include "EnemyB.h"


EnemyB::EnemyB(int x, int y) :Enemy(x,y)
{
	pos.x = STARTPOS;
	pos.y = y;

	sprite = new CSprite("images/Stone/Stone2.png");
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;
	
	moveSpeed = 1000.f;
	gravity = rand() % 3 + 6;
}


EnemyB::~EnemyB()
{

}


void EnemyB::Attack(float eTime)
{
	moveSpeed -= gravity;
	if (moveSpeed < -1000) {
		moveSpeed = -1000;
	}
	pos.x += moveSpeed * eTime;

	sprite->rot += 0.1f;

	shadow->pos.x = pos.x;
	shadow->pos.y = pos.y + 60;
}


void EnemyB::OnEnemyFalse(float eTime) {
	deleteTimer->Update(eTime);
	switch (breakCnt) {
	case 0:
		sprite = new CSprite("images/Stone/Stone2_break1.png");
		break;
	case 1:
		sprite = new CSprite("images/Stone/Stone2_break2.png");
		break;
	case 2:
		sprite = new CSprite("images/Stone/Stone2_break3.png");
		break;
	case 3:
		isDelete = true;
		break;
	}
	if (deleteTimer->isDone) {
		breakCnt++;
	}
}