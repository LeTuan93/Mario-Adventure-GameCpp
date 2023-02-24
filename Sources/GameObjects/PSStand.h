#pragma once
#include "IPState.h"
#include "IPlayer.h"
class PSStand :public IPState {
public:
	PSStand(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(RenderWindow* window);
	void Reset();

private:
	IPlayer* m_Player;
	Animation* m_Animation;

};