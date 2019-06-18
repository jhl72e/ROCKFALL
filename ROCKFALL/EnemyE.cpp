#include "EnemyE.h"



EnemyE::EnemyE(int x, int y) : Enemy(x, y)
{
	sprite = new CSprite("images/Stone/Stone5.png");
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;
	sprite->scalingCenter.x = sprite->width / 2;
	sprite->scalingCenter.y = sprite->height / 2;


	pos.x = x;
	pos.y = y;

	moveSpeed = 0.f;
	gravity = 7.f;

	stdY = rand() % (HEIGHT - 250) + 250;

	isGround = false;

	shadow->sprite->opacity = 0;
	shadow->pos.x = x + 15;
	shadow->pos.y = stdY - 30;
}


EnemyE::~EnemyE()
{

}

void EnemyE::Attack(float eTime) {
	pos.y += moveSpeed * eTime;
	moveSpeed += gravity;
	OnGround();

	sprite->rot += 0.1f;

	shadow->sprite->opacity += 4;
	if (shadow->sprite->opacity >= 255) {
		shadow->sprite->opacity = 255;
	}
	if (isGround) {
		shadow->pos.y += 5;
	}
}

void EnemyE::OnGround() {
	if ((pos.y + sprite->height) > stdY && !isGround) {
		isGround = true;
		moveSpeed = -300.f;
	}
}

void EnemyE::OnEnemyFalse(float eTime) {
	deleteTimer->Update(eTime);
	switch (breakCnt) {
	case 0:
		sprite->scale.x = 0.7f;
		sprite->scale.y = 0.7f;
		break;
	case 1:
		sprite->scale.x = 0.5f;
		sprite->scale.y = 0.5f;
		break;
	case 2:
		sprite->scale.x = 0.3f;
		sprite->scale.y = 0.3f;
		break;
	case 3:
		isDelete = true;
		break;
	}
	if (deleteTimer->isDone) {
		breakCnt++;
	}
}