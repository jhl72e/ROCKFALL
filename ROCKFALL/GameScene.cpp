#include "GameScene.h"
#include "myFunction.h"
#include "SoundMgr.h"

#define GROUND 210

extern SoundMgr *soundMgr;

GameScene::GameScene()
{
	enemyManager = new EnemyManager();
	skillManager = new SkillManager();

	player = new Player();
	spawnTimer = new Timer(1.0f);
	skillTimer = new Timer(10.0f);
	background = new CSprite("images/bgGround.png");
	backgroundBack = new CSprite("images/bgSky.png");
	fallingRock = new CSprite("images/FallingRock.png");
	fallingRock->opacity = 0;
	fallingRock->pos.x = WIDTH / 2 - fallingRock->width / 2;
	fallingRock->pos.y = HEIGHT / 2 - fallingRock->height / 2;

	score = new Score(10, 10, 0.7f);

	scoreTimer = new Timer(1.f);

	enemyEspawn = false;
	enemyEopacUp = true;

	isTimerUpdate = true;

	soundMgr->playLoopSound(BGM_PLAYING);
}


GameScene::~GameScene()
{
	delete player;
	delete enemyManager;
	delete skillManager;
	delete spawnTimer;
	delete skillTimer;
	delete background;
	delete backgroundBack;
	delete fallingRock;
	delete score;
	delete scoreTimer;
}

void GameScene::Update(float eTime)
{
	backGroundMove(eTime);
	player->Update(eTime);
	enemyManager->Update(eTime);
	skillManager->Update(eTime);
	score->Update(eTime);
	if (isTimerUpdate) {
		spawnTimer->Update(eTime);
		skillTimer->Update(eTime);
	}
	if (spawnTimer->isDone)
		SpawnEnemy();
	if (skillTimer->isDone)
		SpawnSkill();

	CollisionCheck();
	OnEnemyScreenOut();
	OnSkillScreenOut();

	if (player->isDelete)
	{
		soundMgr->stopSound(0);
		soundMgr->stopSound(1);
		soundMgr->stopSound(1);

		ChangeScene(new EndScene(score->score));
		return;
	}

	EnemyEspawnUpdate(eTime);
	SkillActiveCheck();

	scoreTimer->Update(eTime);
	if (scoreTimer->isDone) {
		score->AddScore();
	}
}

void GameScene::Render()
{
	backgroundBack->Render(0);
	background->Render(0);
	enemyManager->Render(0);
	player->Render(0);
	skillManager->Render(0);
	if (enemyEspawn) {
		fallingRock->Render(0);
	}
	score->Render(0);
}

void GameScene::SpawnEnemy()
{
	int y = rand() % (HEIGHT - 240 - 90) + 240;
	int r = rand() % 5;
	
	if (r == 0)
	{
		enemyManager->PushEnemy(new EnemyA(STARTPOS, y));
	}
	else if(r == 1)
	{
		enemyManager->PushEnemy(new EnemyB(STARTPOS, y));
	}
	else if (r == 2)
	{
		enemyManager->PushEnemy(new EnemyC(STARTPOS, y));
	}
	else if (r == 3) {
		enemyManager->PushEnemy(new EnemyD(rand() % 250, -100));
	}
	else if (r == 4) {
		enemyManager->PushEnemy(new EnemyESpawner(-300, -300, enemyManager));
		enemyEspawn = true;
		spawnTimer->passedTime = -1.f;
	}
}

void GameScene::SpawnSkill() {
	int y = rand() % (HEIGHT - 300) + 180;
	int r = rand() % 3;

	if (r == 0) {
		skillManager->PushSkill(new SkillA(1400, y, player, enemyManager));
	}
	else if (r == 1) {
		skillManager->PushSkill(new SkillB(1400, y, player, enemyManager));
	}
	else if (r == 2) {
		skillManager->PushSkill(new SkillC(1400, y, player, enemyManager));
	}
}

void GameScene::CollisionCheck()
{
	EnemyList::iterator eiter;
	for (eiter = enemyManager->eList.begin(); eiter != enemyManager->eList.end(); eiter++)
	{
		if (GetDistance((*eiter)->pos + D3DXVECTOR2((*eiter)->sprite->width / 2, (*eiter)->sprite->height / 2),
			player->pos + D3DXVECTOR2(player->sprite->width / 2, player->sprite->height / 2 + 35)) < 70 &&
			(*eiter)->isEnemy)
		{
			player->isDelete = true;
		}
	}
}

void GameScene::backGroundMove(float eTime)
{
	background->pos.y = GROUND;
	background->pos.x -= 700 * eTime;
	backgroundBack->pos.x -= 300 * eTime;
	if (background->pos.x <= -1280)
	{
		background->pos.x = 0;
	}
	if (backgroundBack->pos.x <= -1280)
	{
		backgroundBack->pos.x = 0;
	}
}

void GameScene::OnEnemyScreenOut() {
	EnemyList::iterator eiter;
	for (eiter = enemyManager->eList.begin(); eiter != enemyManager->eList.end(); eiter++) {
		if ((*eiter)->pos.x < -300 || (*eiter)->pos.x > 1580 || (*eiter)->pos.y > 920) {
			(*eiter)->isDelete = true;
		}
	}
}

void GameScene::OnSkillScreenOut() {
	SkillList::iterator siter;
	for (siter = skillManager->sList.begin(); siter != skillManager->sList.end(); siter++) {
		if ((*siter)->pos.x < -700) {
			(*siter)->isDelete = true;
		}
	}
}

void GameScene::EnemyEspawnUpdate(float eTime) {
	if (enemyEspawn) {
		fallingRock->Update(eTime);
		if (enemyEopacUp) {
			fallingRock->opacity += 4;
			if (fallingRock->opacity >= 255) {
				fallingRock->opacity = 255;
				enemyEopacUp = false;
			}
		}
		else {
			fallingRock->opacity -= 4;
			if (fallingRock->opacity <= 0) {
				fallingRock->opacity = 0;
				enemyEopacUp = true;
				enemyEspawn = false;
			}
		}
	}
}

void GameScene::SkillActiveCheck() {
	isTimerUpdate = true;

	SkillList::iterator siter;
	for (siter = skillManager->sList.begin(); siter != skillManager->sList.end(); siter++) {
		if ((*siter)->isActive == true) {
			isTimerUpdate = false;
			break;
		}
	}
}