#include "soundMgr.h"

FMOD_SYSTEM *g_System;
FMOD_SOUND *g_Sound[MaxSound];//사운드 갯수만큼
FMOD_CHANNEL *g_Channel[MaxChannel];//채널 갯수만큼
SoundMgr::SoundMgr()
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, MaxSound, FMOD_INIT_NORMAL, NULL);

	FMOD_System_CreateSound(g_System, "sounds/BGM/Main.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[BGM_MAIN]);
	FMOD_System_CreateSound(g_System, "sounds/BGM/Playing.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[BGM_PLAYING]);
	FMOD_System_CreateSound(g_System, "sounds/BGM/Gameover.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[BGM_GAMEOVER]);

	FMOD_System_CreateSound(g_System, "sounds/SFX/ButtonClick.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_BUTTON_CLICK]);

	FMOD_System_CreateSound(g_System, "sounds/SFX/CutScene_1.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_CUTSCENE_1]);
	FMOD_System_CreateSound(g_System, "sounds/SFX/CutScene_2.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_CUTSCENE_2]);
	FMOD_System_CreateSound(g_System, "sounds/SFX/CutScene_3.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_CUTSCENE_3]);
	FMOD_System_CreateSound(g_System, "sounds/SFX/CutScene_4.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_CUTSCENE_4]);
	FMOD_System_CreateSound(g_System, "sounds/SFX/CutScene_5.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_CUTSCENE_5]);

	FMOD_System_CreateSound(g_System, "sounds/SFX/ActiveSkill.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_ACTIVESKILL]);
	FMOD_System_CreateSound(g_System, "sounds/SFX/Warning.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_WARNING]);
	FMOD_System_CreateSound(g_System, "sounds/SFX/FallingRock.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_FALLINGROCK]);
	FMOD_System_CreateSound(g_System, "sounds/SFX/Gameover.mp3", FMOD_DEFAULT, 0, &g_Sound[SFX_GAMEOVER]);

	/*루프 노말은 계속 돌아가는거 ex)배경음악<FMOD	_LOOP_NORMAL>
	디펄트는 한번 재생후 끝 ex)효과음<FMOD_DEFAULT>
	*/
	//FMOD_System_PlaySound(g_System,FMOD_CHANNEL_FREE,g_Sound[0],0,&g_Channel[0]);//배경 음악 재생
	/*FMOD_CHANNEL_FREE를 쓰면 지금 FREE한 채널 알아서 잡아서 해줌*/
	loopVolume = 0.5f;
	effectVolume = 0.8f;//볼륨 초기화
}
SoundMgr::~SoundMgr()
{
	for (int i = 0; i < MaxSound; i++)
	{
		FMOD_Sound_Release(g_Sound[i]);//사운드들 지워주기
	}
	FMOD_System_Release(g_System);
	FMOD_System_Close(g_System);
}
void SoundMgr::Update()//한프레임씩 읽어오는거라서 계속 업뎃 해줘야함
{
	FMOD_System_Update(g_System);
	FMOD_Channel_SetVolume(g_Channel[0],loopVolume);
	FMOD_Channel_SetVolume(g_Channel[1],effectVolume);
}

void SoundMgr::playLoopSound(int soundNum)//계속반복재생 시켜줄 음악 재생
{
	FMOD_System_PlaySound(g_System,FMOD_CHANNEL_FREE,g_Sound[soundNum],0,&g_Channel[0]);
}

void SoundMgr::playEffectSound(int soundNum)//한 번 재생 시켜줄 음악 재생
{
	FMOD_System_PlaySound(g_System,FMOD_CHANNEL_FREE,g_Sound[soundNum],0,&g_Channel[1]);
}

void SoundMgr::upVolume(int mode)//mode 0=loop 1=effect
{
	if(!mode)
	{
		if (loopVolume < 1.0f)
			loopVolume += 0.1f;
	}
	else
	{
		if (effectVolume < 1.0f)
			effectVolume += 0.1f;
	}
}
void SoundMgr::downVolume(int mode)//mode 0=loop 1=effect
{
	if(!mode)
	{
		if (loopVolume > 0.1f)
			loopVolume -= 0.1f;
	}
	else
	{
		if (effectVolume > 1.0f)
			effectVolume -= 0.1f;
	}
}
void SoundMgr::stopSound(int mode)
{
	FMOD_Channel_Stop(g_Channel[mode]);
}

int SoundMgr::isPlaying(int mode)
{
	FMOD_BOOL IsPlaying;
	FMOD_Channel_IsPlaying(g_Channel[0],&IsPlaying); 
	return IsPlaying;
}

