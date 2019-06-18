#pragma once
#include "Enemy.h"
class EnemyD :
	public Enemy
{
public:
	float gravity;

	int stdY;

	EnemyD(int x, int y);
	~EnemyD();

	void Attack(float eTime);

	void OnEnemyFalse(float eTime);
};

