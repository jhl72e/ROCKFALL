#include "Player.h"
#include "myFunction.h"

Player::Player() :IObject()
{
	sprite = new CSprite("images/player_1.png");
	pos.x = 30;
	pos.y = 520;
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;
	sprite->scalingCenter.x = sprite->width / 2;
	sprite->scalingCenter.y = sprite->height / 2;
	verMoveSpeed = 450.f;
	horMoveSpeed = 350.f;
	animationTimer = new Timer(0.25f);
	spriteIndex = 0;
	shadow = new Shadow();
}

Player::~Player()
{
	delete sprite;
	delete animationTimer;
	delete shadow;
}

void Player::Update(float eTime)
{
	sprite->Update(eTime);
	Move(eTime);
	SpriteUpdate(eTime);
	shadow->pos.x = pos.x;
	shadow->pos.y = pos.y + 145;
}

void Player::Move(float eTime) {
	if (MyKeyState('A') > 0 || MyKeyState(VK_LEFT) > 0)
	{
		pos.x -= verMoveSpeed * eTime;
		if (pos.x < 0)
		{
			pos.x = 0;
		}
		else if (pos.x > WIDTH - sprite->width)
		{
			pos.x = WIDTH - sprite->width;
		}
	}
	if (MyKeyState('D') > 0 || MyKeyState(VK_RIGHT) > 0)
	{
		pos.x += verMoveSpeed * eTime;
		if (pos.x < 0)
		{
			pos.x = 0;
		}
		else if (pos.x > WIDTH - sprite->width)
		{
			pos.x = WIDTH - sprite->width;
		}
	}
	if (MyKeyState('W') > 0 || MyKeyState(VK_UP) > 0)
	{
		pos.y -= horMoveSpeed * eTime;
		if (pos.y < TOP)
		{
			pos.y = TOP;
		}
		else if (pos.y > HEIGHT - sprite->height)
		{
			pos.y = HEIGHT - sprite->height;
		}
	}
	if (MyKeyState('S') > 0 || MyKeyState(VK_DOWN) > 0)
	{
		pos.y += horMoveSpeed * eTime;
		if (pos.y < TOP)
		{
			pos.y = TOP;
		}
		else if (pos.y > HEIGHT - sprite->height)
		{
			pos.y = HEIGHT - sprite->height;
		}
	}
}

void Player::SpriteUpdate(float eTime) {
	animationTimer->Update(eTime);
	if (animationTimer->isDone) {
		spriteIndex++;
		if (spriteIndex > 3) {
			spriteIndex = 0;
		}

		if (spriteIndex == 0) {
			sprite = new CSprite("images/player_1.png");
		}
		else if (spriteIndex == 1 || spriteIndex == 3) {
			sprite = new CSprite("images/player_2.png");
		}
		else if (spriteIndex == 2) {
			sprite = new CSprite("images/player_3.png");
		}
	}
}



void Player::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	shadow->Render(0);
	sprite->Render(&(this->mat));
}
