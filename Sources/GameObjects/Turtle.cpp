#include "Turtle.h"

void Turtle::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(40, 23));
	m_HitBox->Init(sf::Vector2f(-10, 0));
	m_runAni = new Animation(*DATA->getTexture("Monster/Turtle/Idle 1 (44x26)"), Vector2i(14, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/Turtle/Hit (44x26)"), Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}