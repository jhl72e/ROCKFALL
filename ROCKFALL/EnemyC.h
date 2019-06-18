#pragma once
#include "Enemy.h"
class EnemyC :
	public Enemy
{
public:
	EnemyC(int x, int y);
	~EnemyC();

	void Attack(float eTime);
	int r;

	void OnEnemyFalse(float eTime);

};

