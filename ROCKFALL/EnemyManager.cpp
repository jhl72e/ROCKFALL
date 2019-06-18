#include "EnemyManager.h"


EnemyManager::EnemyManager()
{

}


EnemyManager::~EnemyManager()
{
	EnemyList::iterator iter;
	for (iter = eList.begin(); iter != eList.end(); iter++)
	{
		delete (*iter);
	}
}


void EnemyManager::Update(float eTime)
{
	EnemyList::iterator iter;
	for (iter = eList.begin(); iter != eList.end(); iter++)
	{

		(*iter)->Update(eTime);
		if ((*iter)->isDelete)
		{
			iter = PopEnemy(iter);
			if (iter == eList.end())
			{
				break;
			}
		}
	}
}

void EnemyManager::Render(D3DXMATRIX *pmat)
{
	EnemyList::iterator iter;
	for (iter = eList.begin(); iter != eList.end(); iter++)
		(*iter)->Render(pmat);
}

void EnemyManager::PushEnemy(Enemy *pe)
{
	eList.push_back(pe);
}

EnemyList::iterator EnemyManager::PopEnemy(EnemyList::iterator iter)
{
	delete (*iter);
	iter = eList.erase(iter);
	return iter;
}

