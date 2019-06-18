#include "CutScene.h"
#include "GameScene.h"
#include "SoundMgr.h"

extern SoundMgr *soundMgr;

CutScene::CutScene()
{
	cutNum = 1;

	firstCut = new Button("images/CutScene/Scene_1.png", 0, 0);
	secondCut = new Button("images/CutScene/Scene_2.png", 0, 0);
	thirdCut = new Button("images/CutScene/Scene_3.png", 0, 0);
	fourthCut = new Button("images/CutScene/Scene_4.png", 0, 0);
	LastCut = new Button("images/CutScene/Scene_5.png", 0, 0);

	soundMgr->playEffectSound(SFX_CUTSCENE_1);
}


CutScene::~CutScene()
{
	delete firstCut;
	delete secondCut;
	delete thirdCut;
	delete fourthCut;
	delete LastCut;
}



void CutScene::Render()
{
	if (cutNum == 1) {
		firstCut->Render(0);
	}
	else if (cutNum == 2) {
		secondCut->Render(0);
	}
	else if (cutNum == 3) {
		thirdCut->Render(0);
	}
	else if (cutNum == 4)
	{
		fourthCut->Render(0);
	}
	else if (cutNum == 5)
	{
		LastCut->Render(0);
	}
}

void CutScene::Update(float eTime)
{
	if (MyKeyState(VK_LBUTTON) == -1) {
		cutNum++;
		if (cutNum == 2) {
			soundMgr->playEffectSound(SFX_CUTSCENE_2);
		}
		else if (cutNum == 3) {
			soundMgr->playEffectSound(SFX_CUTSCENE_3);
		}
		else if (cutNum == 4) {
			soundMgr->playEffectSound(SFX_CUTSCENE_4);
		}
		else if (cutNum == 5) {
			soundMgr->playEffectSound(SFX_CUTSCENE_5);
		}
	}

	if (cutNum > 5) {
		ChangeScene(new GameScene());
	}
}

