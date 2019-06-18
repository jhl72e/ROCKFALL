#pragma once
#include "Skill.h"
class SkillC :
	public Skill
{
public:
	SkillC(int x, int y, Player *player, EnemyManager *enemyManager);
	~SkillC();
};

