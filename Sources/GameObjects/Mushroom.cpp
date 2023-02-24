#include "Mushroom.h"

void Mushroom::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(32, 32));
	//m_HitBox->Init(sf::Vector2f(-200, 0));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY - 50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);
	m_runAni = new Animation(*DATA->getTexture("Monster/Mushroom/Run (32x32)"), sf::Vector2i(16, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/Mushroom/Hit"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
