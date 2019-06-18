#pragma once
#include "Skill.h"
#include <list>

typedef std::list<Skill*> SkillList;
class SkillManager
{
public:
	SkillList sList;

	SkillManager();
	~SkillManager();
	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
	void PushSkill(Skill *pe);
	SkillList::iterator PopSkill(SkillList::iterator iter);
};