#pragma once
#include "HitBox.h"
#include <list>
class CollisionManager {
public:
	void addObj(HitBox* hitBox);
	bool checkCollision(HitBox* a, HitBox* b);
	void Update();
private:
	list<HitBox*> m_listObj;
};