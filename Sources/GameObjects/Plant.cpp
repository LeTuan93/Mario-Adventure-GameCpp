#include "Plant.h"

void Plant::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(44, 42));
	m_HitBox->Init(sf::Vector2f(-300, 0));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY -50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);
	m_runAni = new Animation(*DATA->getTexture("Monster/Plant/Idle (44x42)"), Vector2i(11, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/Plant/Hit (44x42)"), Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}