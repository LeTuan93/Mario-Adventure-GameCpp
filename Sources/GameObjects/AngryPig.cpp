#include "AngryPig.h"

void AngryPig::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(36, 30));
	m_HitBox->Init(sf::Vector2f(-200, 0));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY -50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);

	m_runAni = new Animation(*DATA->getTexture("Monster/AngryPig/Run (36x30)"), sf::Vector2i(12, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/AngryPig/Hit 1 (36x30)"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
