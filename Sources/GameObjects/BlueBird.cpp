#include "BlueBird.h"

void BlueBird::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(32, 32));
	m_HitBox->Init(Vector2f(-50, 0));
	//setStartPoint(Vector2f(750, 500));
	//m_HitBox->setPosition(750,500);
	//setStartRange(Vector2f(720, 750));
	m_runAni = new Animation(*DATA->getTexture("Monster/BlueBird/Flying (32x32)"), sf::Vector2i(9, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/BlueBird/Hit (32x32)"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
