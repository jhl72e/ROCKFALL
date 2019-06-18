#include "EnemyD.h"
#include "myFunction.h"


EnemyD::EnemyD(int x, int y):Enemy(x,y)
{
	sprite = new CSprite("images/Stone/Stone4.png");
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;

	pos.x = x;
	pos.y = y;

	moveSpeed = 400.f;
	gravity = 8.f;
	stdY = 600;

	shadow->sprite->opacity = 0;
}


EnemyD::~EnemyD()
{

}

void EnemyD::Attack(float eTime)
{
	sprite->rot += 0.1f;
	if (moveSpeed != 0) {
		pos.x += 300 * eTime;
	}

	pos.y += moveSpeed * eTime;
	moveSpeed += gravity;
	if (pos.y >= stdY) {
		moveSpeed = -600.f;
	}

	shadow->pos.x = pos.x;
	shadow->pos.y = 680;

	shadow->sprite->opacity += 4;
	if (shadow->sprite->opacity >= 255) {
		shadow->sprite->opacity = 255;
	}
}

void EnemyD::OnEnemyFalse(float eTime) {
	deleteTimer->Update(eTime);
	switch (breakCnt) {
	case 0:
		sprite = new CSprite("images/Stone/Stone4_break1.png");
		break;
	case 1:
		sprite = new CSprite("images/Stone/Stone4_break2.png");
		break;
	case 2:
		sprite = new CSprite("images/Stone/Stone4_break3.png");
		break;
	case 3:
		isDelete = true;
		break;
	}
	if (deleteTimer->isDone) {
		breakCnt++;
	}
}