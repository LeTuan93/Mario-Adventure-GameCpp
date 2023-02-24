#include "PSAttack.h"

PSAttack::PSAttack(IPlayer* player)
{
	m_Player = player;
}

void PSAttack::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Mario/Attack5"), sf::Vector2i(4, 1), 0.1f);
}

void PSAttack::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_Player->changeNextState(RUN);
		m_Animation->setScale(-1, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Player->changeNextState(RUN);
		m_Animation->setScale(1, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_Player->changeNextState(RUN);
	}
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::DEATH);

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	if ((int)m_Player->getHitBox()->getPosition().y >= groundY) m_Player->changeNextState(DEATH);
}

void PSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSAttack::Reset()
{
	m_Animation->Reset();
}

//Collider PSAttack::GetCollider()
//{
//	return Collider(m_Animation);
//}
