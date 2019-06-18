#include "EnemyC.h"
#include "myFunction.h"

EnemyC::EnemyC(int x, int y):Enemy(x, y)
{
	pos.x = STARTPOS;
	pos.y = 350;

	sprite = new CSprite("images/Stone/Stone3.png");
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;
	
	r = rand() % 2;

	moveSpeed = 400.f;
}


EnemyC::~EnemyC()
{

}

void EnemyC::Attack(float eTime)
{
	pos.x += moveSpeed * eTime;
	
	if (r == 0)
	{
		pos.y += (moveSpeed / 2) * eTime;
		if (pos.y >= HEIGHT - sprite->height)
		{
			r = 1;
		}
	}
	else if (r== 1)
	{
		pos.y -= (moveSpeed / 2) * eTime;
		if (pos.y <= TOP)
		{
			r = 0;
		}
	}

	sprite->rot += 0.1;

	shadow->pos.x = pos.x;
	shadow->pos.y = pos.y + 60;
}

void EnemyC::OnEnemyFalse(float eTime) {
	deleteTimer->Update(eTime);
	switch (breakCnt) {
	case 0:
		sprite = new CSprite("images/Stone/Stone3_break1.png");
		break;
	case 1:
		sprite = new CSprite("images/Stone/Stone3_break2.png");
		break;
	case 2:
		sprite = new CSprite("images/Stone/Stone3_break3.png");
		break;
	case 3:
		isDelete = true;
		break;
	}
	if (deleteTimer->isDone) {
		breakCnt++;
	}
}