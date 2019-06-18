#pragma once
#include "Skill.h"
class SkillB :
	public Skill
{
public:
	SkillB(int x, int y, Player *player, EnemyManager *enemyManager);
	~SkillB();
};

