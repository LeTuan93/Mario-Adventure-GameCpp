#include "Chicken.h"

void Chicken::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(32, 38));
	m_HitBox->Init(sf::Vector2f(-200, 0));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY - 50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);
	m_runAni = new Animation(*DATA->getTexture("Monster/Chicken/Run (32x34)"), sf::Vector2i(14, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/Chicken/Hit (32x34)"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
