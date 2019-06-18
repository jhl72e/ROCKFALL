#pragma once
#include "IScene.h"
#include "Button.h"
#include "myFunction.h"
class TitleScene :
	public IScene
{
public:
	Button *startButton;
	CSprite *background;
	CSprite *backgroundTitle;
	CSprite *backgroundBack;
	
	TitleScene();
	~TitleScene();

	void backGroundMove(float eTime);
	void Render();
	void Update(float eTime);
};

