#pragma once
#include "..//GameManager/ResourceManager.h"

enum TAG
{
	PLAYER,
	CREEP,
	COIN,
};
class HitBox :public sf::RectangleShape {
public:
	HitBox();
	HitBox(Vector2i size);
	~HitBox();
	void Init(Vector2f velocity);

	sf::Vector2f getVelocity();
	void setVelocity(Vector2f velocity);
	TAG getTag() { return m_Tag; };
	void SetTag(TAG tag) { m_Tag = tag; }
	
	bool isAlive() { return m_isAlive; }
	void setAlive(bool alive) { m_isAlive = alive; }
private:
	Vector2f m_Velocity;
	bool m_isAlive;
	TAG m_Tag;
};