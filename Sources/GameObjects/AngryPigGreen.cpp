#include "AngryPigGreen.h"

void AngryPigGreen::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(36, 30));
	m_HitBox->Init(sf::Vector2f(-100, 0));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY -50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);

	m_runAni = new Animation(*DATA->getTexture("Monster/AngryPig/Walk (36x30)"), sf::Vector2i(16, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/AngryPig/Hit 2 (36x30)"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
