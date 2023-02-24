#include "Chameleon.h"

void Chameleon::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(20, 35));
	m_HitBox->Init(sf::Vector2f(-50, 0));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY - 50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);
	m_runAni = new Animation(*DATA->getTexture("Monster/Chameleon/Attack (84x38)"),Vector2i(10, 1), 0.1f);
	//m_AttackAni = new Animation(*DATA->getTexture("Monster/Chameleon/Attack (84x38)"),Vector2i(10, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/Chameleon/Hit (84x38)"),Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	if (rand()%2 == 1) m_currentAni = m_runAni;
	else m_currentAni = m_AttackAni;
	m_HitBox->SetTag(CREEP);
}
