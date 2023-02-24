#include "Creep.h"

Creep::Creep()
{
	m_stop = true;
}

Creep::~Creep()
{
	m_currentAni = nullptr;
	if (m_deathAni != nullptr) {
		delete m_deathAni;
	}
	if (m_runAni != nullptr) {
		delete m_runAni;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
	}
}

void Creep::Init()
{
}

void Creep::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_HitBox->isAlive()) {
		m_currentAni->Update(deltaTime);
		m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		if (m_HitBox->getPosition().x <= getStartRange().x) {
			m_currentAni->setScale(-1, 1);
			m_HitBox->Init(Vector2f(100, 0));
		}
		else  if (m_HitBox->getPosition().x > getStartRange().y)
		{
			m_currentAni->setScale(1, 1);
			m_HitBox->Init(Vector2f(-100, 0));
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

void Creep::Render(sf::RenderWindow* window)
{
	if (m_stop) return;
	window->draw(*m_currentAni);
	//window->draw(*m_HitBox);
}

void Creep::Reset()
{
	m_stop = false;
	m_deathAni->Reset();
	m_runAni->Reset();
	m_currentAni = m_runAni;
	m_HitBox->setPosition(m_startPoint);
}
