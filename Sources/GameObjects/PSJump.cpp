#include "PSJump.h"

PSJump::PSJump(IPlayer* player)
{
	m_Player = player;
	m_currentTime = 0.f;
}

void PSJump::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Mario/Jump"), sf::Vector2i(5, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PSJump::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	
	float v = 10 * m_currentTime;
	if (-m_Player->getHitBox()->getVelocity().y * deltaTime + v >= 0) {
		m_Player->changeNextState(FALL);
		m_currentTime = 0.f;
	}
	else m_Player->getHitBox()->move(0, -m_Player->getHitBox()->getVelocity().y * deltaTime+v);
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		m_Animation->setScale(-1, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		m_Animation->setScale(1, 1);
	}
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::FALL);
	m_Player->resetCollision();
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	if ((int)m_Player->getHitBox()->getPosition().y >= groundY) m_Player->changeNextState(DEATH);
	//if (m_Player->getHitBox()->getPosition().x >= 500) m_Player->changeNextState(STAND);

}

void PSJump::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSJump::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0;
}
