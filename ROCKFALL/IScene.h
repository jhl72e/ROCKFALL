#pragma once

class IScene {
public:

	IScene() {}
	virtual ~IScene() {}
	virtual void Render() = 0;
	virtual void Update(float eTime) = 0;
};