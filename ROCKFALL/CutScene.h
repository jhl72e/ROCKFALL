#pragma once
#include "IScene.h"
#include "Button.h"
#include "myFunction.h"
class CutScene :
	public IScene
{
public:
	CutScene();
	~CutScene();

	Button *firstCut;
	Button *secondCut;
	Button *thirdCut;
	Button *fourthCut;
	Button *LastCut;

	int cutNum;

	void Render();
	void Update(float eTime);
};


