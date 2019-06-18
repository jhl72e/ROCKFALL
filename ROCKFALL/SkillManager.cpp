#include "SkillManager.h"


SkillManager::SkillManager()
{

}


SkillManager::~SkillManager()
{
	SkillList::iterator iter;
	for (iter = sList.begin(); iter != sList.end(); iter++)
	{
		delete (*iter);
	}
}


void SkillManager::Update(float eTime)
{
	SkillList::iterator iter;
	for (iter = sList.begin(); iter != sList.end(); iter++)
	{

		(*iter)->Update(eTime);
		if ((*iter)->isDelete)
		{
			iter = PopSkill(iter);
			if (iter == sList.end())
			{
				break;
			}
		}
	}
}

void SkillManager::Render(D3DXMATRIX *pmat)
{
	SkillList::iterator iter;
	for (iter = sList.begin(); iter != sList.end(); iter++)
		(*iter)->Render(pmat);
}

void SkillManager::PushSkill(Skill *pe)
{
	sList.push_back(pe);
}

SkillList::iterator SkillManager::PopSkill(SkillList::iterator iter)
{
	delete (*iter);
	iter = sList.erase(iter);
	return iter;
}

