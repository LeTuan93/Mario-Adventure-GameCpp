#pragma once
#include "HitBox.h"

class BlockCollisionManager {
public:
	BlockCollisionManager(HitBox& hitBox);
	~BlockCollisionManager();
	void Move(float dx, float dy) { hitBox.move(dx, dy); }

	bool CheckBlockCollider(BlockCollisionManager other);
	Vector2f GetPosition() { return hitBox.getPosition(); }
	Vector2f GetHalfSize() { return hitBox.getSize() / 2.f; }

	static int checkColl() { return check; };
	static void ResetColl() { check = 0; };
	static int check;
private:
	HitBox& hitBox;
	vector<HitBox*> m_listObj;
};