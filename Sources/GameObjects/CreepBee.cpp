#include "CreepBee.h"

void CreepBee::Init()
{
	m_HitBox = new HitBox(Vector2i(30, 30));
	m_HitBox->Init(Vector2f(-20, 0));
	m_runAni = new Animation(*DATA->getTexture("Monster/Bee/Attack (36x34)"), sf::Vector2i(8, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/Bee/Hit (36x34)"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}