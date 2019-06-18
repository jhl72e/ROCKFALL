#include "SkillC.h"



SkillC::SkillC(int x, int y, Player *player, EnemyManager *enemyManager) : Skill(player, enemyManager)
{
	sprite = new CSprite("images/skillC.png");
	pos.x = x;
	pos.y = y;

	activeSprite = new CSprite("images/skill_tree.png");
}


SkillC::~SkillC()
{

}