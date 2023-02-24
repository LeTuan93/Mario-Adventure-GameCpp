#include "PSStand.h"
PSStand::PSStand(IPlayer* player)
{
	m_Player = player;
	m_Player->checkFall = 1;
}

void PSStand::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Mario/Stand3"), sf::Vector2i(5, 1), 0.1f);

}

void PSStand::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);

	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D))
	{
		m_Player->changeNextState(RUN);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_Animation->setScale(-1, 1);
		}
		else
		{
			m_Animation->setScale(1, 1);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::W)) {
		m_Player->changeNextState(JUMP);
	}
	else  if (Keyboard::isKeyPressed(Keyboard::Space)) {
		m_Player->changeNextState(ATTACK);
	}

	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(DEATH);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	if ((int)m_Player->getHitBox()->getPosition().y >= groundY) m_Player->changeNextState(DEATH);

}

void PSStand::Render(RenderWindow* window)
{
	window->draw(*m_Animation);
}


void PSStand::Reset()
{

	m_Animation->Reset();
}

