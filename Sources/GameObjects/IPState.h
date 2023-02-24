#pragma once
#include "../GameManager/ResourceManager.h"
class IPState {
public:
	enum STATE
	{
		STAND,
		RUN,
		JUMP,
		FALL,
		ATTACK,
		DEATH,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};
