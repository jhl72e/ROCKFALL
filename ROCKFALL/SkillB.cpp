#include "SkillB.h"


SkillB::SkillB(int x, int y, Player *player, EnemyManager *enemyManager) : Skill(player, enemyManager)
{
	sprite = new CSprite("images/skillB.png");
	pos.x = x;
	pos.y = y;

	activeSprite = new CSprite("images/skill_sheep.png");
}

SkillB::~SkillB()
{

}