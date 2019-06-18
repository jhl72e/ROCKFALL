#pragma once
#include "IScene.h"
#include "Player.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "EnemyD.h"
#include "EnemyE.h"
#include "EnemyESpawner.h"
#include "EnemyManager.h"
#include "Timer.h"
#include "Sprite.h"
#include "Def.h"
#include "myFunction.h"
#include "EndScene.h"
#include "SkillManager.h"
#include "SkillA.h"
#include "SkillB.h"
#include "SkillC.h"
#include "Score.h"

class GameScene :
	public IScene
{
public:
	enum State
	{
		SPAWNING,
		MOVING,
		ATTACKING
	};
	EnemyManager *enemyManager;
	SkillManager *skillManager;

	CSprite *background;
	CSprite *backgroundBack;
	CSprite *fallingRock;
	Timer *spawnTimer;
	Timer *skillTimer;
	Player *player;
	Score *score;

	Timer *scoreTimer;

	bool flag = false;
	bool enemyEspawn;
	bool enemyEopacUp;

	bool isTimerUpdate;

	GameScene();
	~GameScene();
	float EnemyPos;
	void SpawnEnemy();
	void SpawnSkill();
	void OnEnemyScreenOut();
	void OnSkillScreenOut();
	void Update(float eTime);
	void Render();
	void CollisionCheck();
	void backGroundMove(float eTime);
	void EnemyEspawnUpdate(float eTime);
	void SkillActiveCheck();
};

