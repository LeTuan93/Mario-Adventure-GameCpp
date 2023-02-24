#include "BlockCollisionManager.h"
int BlockCollisionManager::check = -1;

BlockCollisionManager::BlockCollisionManager(HitBox& hitBox) : hitBox(hitBox)
{

}

BlockCollisionManager::~BlockCollisionManager()
{
}

bool BlockCollisionManager::CheckBlockCollider(BlockCollisionManager other)
{
	Vector2f otherPosition = other.GetPosition();
	Vector2f otherHalfSize = other.GetHalfSize();
	Vector2f thisPosition = GetPosition();
	Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + otherHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + otherHalfSize.y);
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				other.Move(-intersectX+1, 0.0f);
				check = -1;
			}
			else {
				other.Move(intersectX-1, 0.0f);
				check = 1;
			}
		}
		else {
			if (deltaY > 0.0f)
			{
				other.Move(0.0f, -intersectY);
				check = -2;
			}
			else {
				other.Move(0.0f, intersectY);
				check = 2;
			}
		}
		return true;
		
	}
	return false;
}
