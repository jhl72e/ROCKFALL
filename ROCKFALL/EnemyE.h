#pragma once
#include "Enemy.h"
class EnemyE :
	public Enemy
{
public:
	int stdY;
	float gravity;

	bool isGround;

	EnemyE(int x, int y);
	~EnemyE();

	void Attack(float eTime);
	void OnGround();

	void OnEnemyFalse(float eTime);

};

