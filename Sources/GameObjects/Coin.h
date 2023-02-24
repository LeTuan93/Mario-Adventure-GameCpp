#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"
class Coin {
public:
	Coin();
	~Coin();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(RenderWindow* window);

	HitBox* getHitBox() { return m_HitBox; }
	void setStartPoint(Vector2f point) { m_startPoint = point; }
	Vector2f getStartPoint() { return m_startPoint; }
	void Reset();
	bool isStop() { return m_stop; }
protected:
	Vector2f m_startPoint;
	HitBox* m_HitBox;
	Animation* m_currentCoin;
	Animation* m_deathCoin;
	Animation* m_runCoin;
	bool m_stop;

	bool m_soundEatGold;
};