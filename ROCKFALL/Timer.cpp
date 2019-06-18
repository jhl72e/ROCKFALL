#include "Timer.h"


Timer::Timer(float goalTime, bool autoReset)
{
	this->goalTime = goalTime;
	this->autoReset = autoReset;
	passedTime = 0.f;
	isDone = false;
}


Timer::~Timer()
{

}

void Timer::Update(float eTime)
{
	if (isDone&&autoReset)
		isDone = false;
	passedTime += eTime;
	if (passedTime >= goalTime)
	{
		isDone = true;
		if (autoReset == true)	
			passedTime -= goalTime;
	}
	
}
void Timer::Reset(float goalTime)
{
	passedTime = 0;
	this->goalTime = goalTime;
	isDone = false;
}
