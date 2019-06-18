#pragma once
class Timer
{
public:
	float passedTime;
	float goalTime;
	bool isDone;
	bool autoReset;


	Timer(float goalTime, bool autoReset = true);
	~Timer();

	void Update(float eTime);
	void Reset(float goalTime);
};