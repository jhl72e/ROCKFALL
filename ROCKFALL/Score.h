#pragma once
#include "IObject.h"
#include "Sprite.h"
class Score :
	public IObject
{
public:
	int score;
	int x, y;

	int digit;

	float scale;

	bool isRender[3][10];

	CSprite *number[3][10];

	Score(int _x, int _y, float _scale);
	~Score();

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);

	void AddScore();
};

