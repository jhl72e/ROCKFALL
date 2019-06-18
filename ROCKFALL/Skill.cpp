#include "Skill.h"
#include "SoundMgr.h"
#include "GameScene.h"

extern SoundMgr *soundMgr;

Skill::Skill(Player *player, EnemyManager *enemyManager)
{
	activeSprite = new CSprite("images/dot.png");
	activeSprite->pos.x = 0;
	activeSprite->pos.y = 0;

	this->player = player;
	this->enemyManager = enemyManager;
	moveSpeed = 200.f;

	activeSprite->opacity = 0;

	startendActiveTimer = new Timer(0.5f);
	activeTimer = new Timer(2.f);

	soundTimer = new Timer(1.2f);
	isSound = false;

	isActive = false;
	isActSprOpacState = 0;
}

Skill::~Skill()
{
	delete sprite;
	delete activeSprite;
	delete startendActiveTimer;
	delete activeTimer;
	delete soundTimer;
}


void Skill::Update(float eTime) {
	CollisionCheck();
	pos.x -= moveSpeed * eTime;
	if (pos.x < -300) {
		isDelete = true;
	}
	if (isActive) {
		ActiveSkill(eTime);
	}
}

void Skill::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	sprite->Render(&mat);
	if (isActive) {
		activeSprite->Render(0);
	}
}

void Skill::CollisionCheck() {
	if (GetDistance(pos + D3DXVECTOR2(sprite->width / 2, sprite->height / 2),
		player->pos + D3DXVECTOR2(player->sprite->width / 2, player->sprite->height / 2 + 20)) < 100 &&
		isActive == false) {
		soundMgr->stopSound(1);
		soundMgr->playEffectSound(SFX_ACTIVESKILL);
		isActive = true;
	}
}

void Skill::ActiveSkill(float eTime) {

	EnemyList::iterator eiter;
	for (eiter = enemyManager->eList.begin(); eiter != enemyManager->eList.end(); eiter++) {
		(*eiter)->moveSpeed = 0.f;
	}
	moveSpeed = 0.f;
	player->horMoveSpeed = 0.f;
	player->verMoveSpeed = 0.f;

	if (isActSprOpacState == 0) {
		activeSprite->opacity += 8;
		startendActiveTimer->Update(eTime);
		
		if (startendActiveTimer->isDone) {
			isActSprOpacState = 1;
		}
	}
	else if (isActSprOpacState == 1) {
		activeTimer->Update(eTime);
		if (activeTimer->isDone) {
			isActSprOpacState = 2;
		}
	}
	else if (isActSprOpacState == 2) {
		activeSprite->opacity -= 8;
		startendActiveTimer->Update(eTime);
		if (activeSprite->opacity < 0) {
			activeSprite->opacity = 0;
		}
		if (startendActiveTimer->isDone) {
			for (eiter = enemyManager->eList.begin(); eiter != enemyManager->eList.end(); eiter++) {
				(*eiter)->isEnemy = false;
			}
			player->verMoveSpeed = 450.f;
			player->horMoveSpeed = 350.f;
			isSound = false;
			isDelete = true;
		}
	}

	soundTimer->Update(eTime);
	if (soundTimer->isDone && !isSound) {
		soundMgr->playEffectSound(SFX_FALLINGROCK);
		isSound = true;
	}
}