#include "Bunny.h"

void Bunny::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(30, 40));
	m_HitBox->Init(sf::Vector2f(-100, 0));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY - 50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);
	m_runAni = new Animation(*DATA->getTexture("Monster/Bunny/Run (34x44)"), sf::Vector2i(12, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/Bunny/Hit (34x44)"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
