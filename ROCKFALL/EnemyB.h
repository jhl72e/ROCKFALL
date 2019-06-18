#pragma once
#include "Enemy.h"
#include "Def.h"
class EnemyB :
	public Enemy
{
public:
	EnemyB(int x, int y);
	~EnemyB();

	float gravity;

	void Attack(float eTime);

	void OnEnemyFalse(float eTime);
};