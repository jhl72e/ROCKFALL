#include "TitleScene.h"
#include "GameScene.h"
#include "CutScene.h"
#include "SoundMgr.h"
#include <string>

extern SoundMgr *soundMgr;

TitleScene::TitleScene()
{
	startButton = new Button("images/Button/startButton.png", 528, 500);
	backgroundTitle = new CSprite("images/backgroundTitle.png");
	background = new CSprite("images/bgGround.png");
	backgroundBack = new CSprite("images/bgSky.png");

	backgroundTitle->pos.x = WIDTH / 2 - backgroundTitle->width / 2;
	backgroundTitle->pos.y = 100;

	soundMgr->playLoopSound(BGM_MAIN);
}

TitleScene::~TitleScene()
{
	delete startButton;
	delete background;
	delete backgroundBack;
	delete backgroundTitle;

	soundMgr->stopSound(0);
}

void TitleScene::Update(float eTime)
{
	startButton->Update(eTime);
	backGroundMove(eTime);
	if (startButton->CheckMouse()) {
		startButton->sprite = new CSprite("images/Button/startButtonOver.png");
	}
	else {
		startButton->sprite = new CSprite("images/Button/startButton.png");
	}
	if (MyKeyState(VK_LBUTTON) == -1 &&
		startButton->CheckMouse())
	{
		soundMgr->playEffectSound(SFX_BUTTON_CLICK);
		ChangeScene(new CutScene());
	}
}

void TitleScene::Render()
{
	backgroundBack->Render(0);
	background->Render(0);
	startButton->Render(0);
	backgroundTitle->Render(0);
}


void TitleScene::backGroundMove(float eTime)
{
	background->pos.y = 210;
	background->pos.x -= 700 * eTime;
	backgroundBack->pos.x -= 300 * eTime;
	if (background->pos.x <= -1280)
	{
		background->pos.x = 0;
	}
	if (backgroundBack->pos.x <= -1280)
	{
		backgroundBack->pos.x = 0;
	}
}