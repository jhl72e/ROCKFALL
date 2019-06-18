#pragma once
#pragma once
#include "inc/fmod.hpp"
#pragma comment(lib,"fmodex_vc.lib")
using namespace FMOD;
#include <windows.h>
#define MaxSound 13	 //�Ҹ� ����
#define MaxChannel 2 //0��ä�� ������ 1��ä�� ȿ����

enum
{
	BGM_MAIN,
	BGM_PLAYING,
	BGM_GAMEOVER,

	SFX_BUTTON_CLICK,

	SFX_CUTSCENE_1,
	SFX_CUTSCENE_2,
	SFX_CUTSCENE_3,
	SFX_CUTSCENE_4,
	SFX_CUTSCENE_5,

	SFX_ACTIVESKILL,
	SFX_WARNING,
	SFX_FALLINGROCK,

	SFX_GAMEOVER
};

class SoundMgr
{
public:
	SoundMgr();
	~SoundMgr();

	float effectVolume;
	float loopVolume;

	void Update();
	void playLoopSound(int soundNum);
	void playEffectSound(int soundNum);
	void stopSound(int mode);

	int isPlaying(int mode);

	void upVolume(int mode);
	void downVolume(int mode);
};