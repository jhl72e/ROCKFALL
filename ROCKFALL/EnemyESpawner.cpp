#include "EnemyESpawner.h"
#include "SoundMgr.h"

extern SoundMgr *soundMgr;

EnemyESpawner::EnemyESpawner(int x, int y, EnemyManager *enemyManager) : Enemy(x, y)
{
	sprite = new CSprite("images/dot.png");

	pos.x = x;
	pos.y = y;

	this->enemyManager = enemyManager;

	spawnTimer = new Timer(1.f);
	attackTimer = new Timer(0.3f);
	deleteTimer = new Timer(2.f);

	isAttack = false;

	soundMgr->playEffectSound(SFX_WARNING);
}


EnemyESpawner::~EnemyESpawner()
{
	delete spawnTimer;
	delete attackTimer;
	delete deleteTimer;
}

void EnemyESpawner::Attack(float eTime) {
	AttackSet(eTime);
	deleteTimer->Update(eTime);
	if (deleteTimer->isDone) {
		isDelete = true;
	}
}


void EnemyESpawner::AttackSet(float eTime) {
	if (!isAttack) {
		spawnTimer->Update(eTime);
		if (spawnTimer->isDone) {
			isAttack = true;
		}
	}
	else {
		attackTimer->Update(eTime);
		if (attackTimer->isDone) {
			enemyManager->PushEnemy(new EnemyE(rand() % 1190, -200));
		}
	}

}

void EnemyESpawner::OnEnemyFalse(float eTime) {}