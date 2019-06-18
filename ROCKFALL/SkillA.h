#pragma once
#include "Skill.h"
class SkillA :
	public Skill
{
public:
	SkillA(int x, int y, Player *player, EnemyManager *enemyManager);
	~SkillA();
};

