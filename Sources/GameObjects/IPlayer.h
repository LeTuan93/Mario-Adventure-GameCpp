#pragma once
#include "IPState.h"

#include "../GameConfig.h"
#include "BlockCollisionManager.h"
#include "IPState.h"
using namespace sf;

class IPlayer
{
public:
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	BlockCollisionManager* check;
	int checkFall;
	int checkCollision() { return check->checkColl(); };
	void resetCollision() { return check->ResetColl(); };
};
