#include "EndScene.h"
#include "EndScene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "myFunction.h"
#include "SoundMgr.h"

extern SoundMgr *soundMgr;


EndScene::EndScene(int _score)
{
	endButton = new Button("images/Button/endButton.png", 300, 520);
	backgroundTitle = new CSprite("images/endSceneTitle.png");
	background = new CSprite("images/gameover_background.png");
	endGame = new Button("images/Button/endGame.png",700, 520);
	homeButton = new Button("images/Button/homeButton.png", 1100, 560);
	scoreText = new CSprite("images/scoreText.png");
	score = new Score(750, 320, 0.5f);

	backgroundTitle->pos.x = WIDTH / 2 - backgroundTitle->width / 2;
	backgroundTitle->pos.y = 100;

	scoreText->pos.x = 400;
	scoreText->pos.y = 320;

	score->score = _score;

	BGMtimer = new Timer(2.5f);

	isBGMplay = false;

	soundMgr->playLoopSound(SFX_GAMEOVER);
}


EndScene::~EndScene()
{
	delete endButton;
	delete background;
	delete backgroundTitle;
	delete endGame;
	delete homeButton;
	delete scoreText;
	delete score;
	delete BGMtimer;
}


void EndScene::Render()
{
	background->Render(0);
	endButton->Render(0);
	endGame->Render(0);
	backgroundTitle->Render(0);
	homeButton->Render(0);
	scoreText->Render(0);
	score->Render(0);
}



void EndScene::Update(float eTime)
{
	endButton->Update(eTime);
	score->Update(eTime);

	if (!isBGMplay) {
		BGMtimer->Update(eTime);
		if (BGMtimer->isDone) {
			isBGMplay = true;
			soundMgr->playLoopSound(BGM_GAMEOVER);
		}
	}

	if (endButton->CheckMouse()) {
		endButton->sprite = new CSprite("images/Button/endButtonOver.png");
	}
	else {
		endButton->sprite = new CSprite("images/Button/endButton.png");
	}
	if (endGame->CheckMouse()) {
		endGame->sprite = new CSprite("images/Button/endGameOver.png");
	}
	else {
		endGame->sprite = new CSprite("images/Button/endGame.png");
	}
	if (homeButton->CheckMouse()) {
		homeButton->sprite = new CSprite("images/Button/homeButtonOver.png");
	}
	else {
		homeButton->sprite = new CSprite("images/Button/homeButton.png");
	}

	if (MyKeyState(VK_LBUTTON) == -1 &&
		endButton->CheckMouse())
	{
		soundMgr->stopSound(0);
		soundMgr->stopSound(1);
		soundMgr->playEffectSound(SFX_BUTTON_CLICK);
		ChangeScene(new GameScene());
	}
	else if (MyKeyState(VK_LBUTTON) == -1 &&
		endGame->CheckMouse())
	{
		exit(0);
	}
	else if (MyKeyState(VK_LBUTTON) == -1 &&
		homeButton->CheckMouse())
	{
		soundMgr->stopSound(0);
		soundMgr->stopSound(1);
		soundMgr->playEffectSound(SFX_BUTTON_CLICK);
		ChangeScene(new TitleScene());
	}

}

