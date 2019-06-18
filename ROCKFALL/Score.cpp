#include "Score.h"

Score::Score(int _x, int _y, float _scale)
{
	x = _x;
	y = _y;
	scale = _scale;

	for (int i = 0; i < 3; i++) {
		number[i][0] = new CSprite("images/number/0.png");
		number[i][1] = new CSprite("images/number/1.png");
		number[i][2] = new CSprite("images/number/2.png");
		number[i][3] = new CSprite("images/number/3.png");
		number[i][4] = new CSprite("images/number/4.png");
		number[i][5] = new CSprite("images/number/5.png");
		number[i][6] = new CSprite("images/number/6.png");
		number[i][7] = new CSprite("images/number/7.png");
		number[i][8] = new CSprite("images/number/8.png");
		number[i][9] = new CSprite("images/number/9.png");

		for (int j = 0; j < 10; j++) {
			number[i][j]->pos.x = x + i * 140 * scale;
			number[i][j]->pos.y = y;
			number[i][j]->scale.x = scale;
			number[i][j]->scale.y = scale;
			isRender[i][j] = false;
		}
	}

	score = 0;
	digit = 0;
}

Score::~Score()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			delete number[i][j];
		}
	}
}

void Score::Update(float eTime) {
	if (score / 10 == 0) {
		digit = 1;
	}
	else if (score / 100 == 0) {
		digit = 2;
	}
	else {
		digit = 3;
	}

	if (digit == 1) {
		for (int i = 0; i < 10; i++) {
			if (i == score) {
				isRender[0][i] = true;
			}
			else {
				isRender[0][i] = false;
			}
		}
	}
	else if (digit == 2) {
		int score1 = score % 10;
		int score10 = score / 10;
		for (int i = 0; i < 10; i++) {
			if (i == score10) {
				isRender[0][i] = true;
			}
			else {
				isRender[0][i] = false;
			}
			if (i == score1) {
				isRender[1][i] = true;
			}
			else {
				isRender[1][i] = false;
			}
		}
	}
	else if (digit == 3) {
		int score1 = score % 10;
		int score10 = score / 10 % 10;
		int score100 = score / 100;
		for (int i = 0; i < 10; i++) {
			if (i == score100) {
				isRender[0][i] = true;
			}
			else {
				isRender[0][i] = false;
			}
			if (i == score10) {
				isRender[1][i] = true;
			}
			else {
				isRender[1][i] = false;
			}
			if (i == score1) {
				isRender[2][i] = true;
			}
			else {
				isRender[2][i] = false;
			}
		}
	}
}

void Score::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (isRender[i][j]) {
				number[i][j]->Render(0);
			}
		}
	}
}

void Score::AddScore() {
	score++;
}