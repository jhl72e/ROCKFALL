#pragma once
#include "IScene.h"
#include "Button.h"
#include "Score.h"
#include "Timer.h"
class EndScene :
	public IScene
{
public:

	Button *endButton;
	CSprite *background;
	CSprite *backgroundTitle;
	Button *endGame;
	Button *homeButton;
	CSprite *scoreText;
	Score *score;

	Timer *BGMtimer;

	bool isBGMplay;

	EndScene(int _score);
	~EndScene();

	void Render();
	void Update(float eTime);
};
