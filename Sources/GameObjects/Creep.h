#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"
class Creep {
public:
	Creep();
	~Creep();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);

	HitBox* getHitBox() { return m_HitBox; }
	void setStartPoint(Vector2f point) { m_startPoint = point; }
	void setStartRange(Vector2f range) { m_rangeAni = range; }
	Vector2f getStartRange() { return m_rangeAni; }
	void Reset();
	bool isStop() { return m_stop; }
protected :
	Vector2f m_startPoint;
	HitBox* m_HitBox;
	Animation* m_currentAni;
	Animation* m_deathAni;
	Animation* m_runAni;
	Animation* m_AttackAni;
	Vector2f m_rangeAni;
	bool m_stop;

	bool soundDeadisPlaying;
};