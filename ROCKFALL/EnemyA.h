#pragma once
#include "Enemy.h"
#include "Def.h"
class EnemyA :
	public Enemy
{
public:
	EnemyA(int x, int y);
	~EnemyA();

	void Attack(float eTime);

	void OnEnemyFalse(float eTime);
};

