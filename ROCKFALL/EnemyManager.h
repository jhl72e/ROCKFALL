#pragma once
#include "Enemy.h"
#include <list>

typedef std::list<Enemy*> EnemyList;
class EnemyManager
{
public:
	EnemyList eList;

	EnemyManager();
	~EnemyManager();
	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
	void PushEnemy(Enemy *pe);
	EnemyList::iterator PopEnemy(EnemyList::iterator iter);
};



