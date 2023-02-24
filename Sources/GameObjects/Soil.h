#pragma once
#include "../GameManager/ResourceManager.h"
#include "BlockCollisionManager.h";

class Soil {
private:
	HitBox m_HitBox;
public:
	Soil();
	Soil(Vector2f size,Vector2f position);
	~Soil();
	void Render(RenderWindow* window);
	BlockCollisionManager GetBlockCollider() { return BlockCollisionManager(m_HitBox); }
};