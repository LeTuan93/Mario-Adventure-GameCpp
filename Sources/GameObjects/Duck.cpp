#include "Duck.h"

void Duck::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(44, 30));
	m_HitBox->Init(sf::Vector2f(-300, 0));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY -50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);
	m_runAni = new Animation(*DATA->getTexture("Monster/Duck/Jump Anticipation (36x36)"), Vector2i(4, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/Duck/Hit (36x36)"), Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}