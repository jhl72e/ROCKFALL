#pragma once
#include "Enemy.h"
#include "EnemyManager.h"
#include "EnemyE.h"
class EnemyESpawner :
	public Enemy
{
public:
	bool isAttack;

	EnemyManager *enemyManager;

	Timer *spawnTimer;
	Timer *attackTimer;
	Timer *deleteTimer;

	EnemyESpawner(int x, int y, EnemyManager *enemyManager);
	~EnemyESpawner();

	void Attack(float eTime);

	void AttackSet(float eTime);

	void OnEnemyFalse(float eTime);
};

