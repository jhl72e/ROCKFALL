#include "SkillA.h"



SkillA::SkillA(int x, int y, Player *player, EnemyManager *enemyManager) : Skill(player, enemyManager)
{
	sprite = new CSprite("images/skillA.png");
	pos.x = x;
	pos.y = y;

	activeSprite = new CSprite("images/skill_chicken.png");
}

SkillA::~SkillA()
{

}