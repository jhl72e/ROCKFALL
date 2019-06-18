#pragma once
#include "IObject.h"
#include "Sprite.h"
#include "myFunction.h"
#include "Player.h"
#include "EnemyManager.h"

class Skill :
	public IObject
{
public:
	float moveSpeed;

	bool isActive;
	int isActSprOpacState;

	Player *player;
	EnemyManager *enemyManager;

	CSprite *sprite;
	CSprite *activeSprite;

	Timer *startendActiveTimer;
	Timer *activeTimer;

	Timer *soundTimer;
	bool isSound;

	Skill(Player *player, EnemyManager *enemyManager);
	~Skill();

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);

	void CollisionCheck();
	void ActiveSkill(float eTime);
};

