#include "Duck.h"
#include "FatBird.h"

void FatBird::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(40, 48));
	m_HitBox->Init(sf::Vector2f(0,-300));
	//setStartPoint(sf::Vector2f(screenWidth + rand() % 100, groundY -50));
	//m_HitBox->setPosition(screenWidth, groundY - 50);
	m_runAni = new Animation(*DATA->getTexture("Monster/FatBird/Idle (40x48)"), Vector2i(8, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Monster/FatBird/Hit (40x48)"), Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}

void FatBird::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_HitBox->isAlive()) {
		m_currentAni->Update(deltaTime);
		m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		if (m_HitBox->getPosition().y <= getStartRange().x) {
			m_currentAni->setScale(-1, 1);
			m_HitBox->Init(Vector2f(0, 200));
		}
		else  if (m_HitBox->getPosition().y > getStartRange().y)
		{
			m_currentAni->setScale(1, 1);
			m_HitBox->Init(Vector2f(0, -200));
		}
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		m_currentAni = m_deathAni;
		if (m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1) {
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition());
		}
		else m_stop = true;

	}
}
