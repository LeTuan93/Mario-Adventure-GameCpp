#include "PSRun.h"
PSRun::PSRun(IPlayer* player)
{
	m_Player = player; 
}

void PSRun::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Mario/Run"), sf::Vector2i(8, 1), 0.1f);
	

}

void PSRun::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Player->checkFall = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		m_Animation->setScale(-1, 1);
		if (m_Player->checkCollision() == 0)
		{
			//printf("A\n");
			//printf("    %f", m_Player->checkCollision());
			m_Player->changeNextState(FALL);
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		m_Animation->setScale(1, 1);
		if (m_Player->checkCollision() == 0)
		{
			//printf("D\n");
			m_Player->changeNextState(FALL);
			return;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_Player->changeNextState(ATTACK);
	}
	else
	{
		m_Player->changeNextState(STAND);
	}
	if (Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_Player->changeNextState(JUMP);
	}
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(DEATH);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	if ((int)m_Player->getHitBox()->getPosition().y >= groundY) m_Player->changeNextState(DEATH);
	//if (m_Player->getHitBox()->getPosition().x >= 500) m_Player->changeNextState(STAND);
	//printf("%f   ", m_Player->getHitBox()->getPosition().y);
	//printf("%d\n", groundY);

\
	//printf("%d ", m_Player->checkCollision());
	//if (m_Player->checkCollision() == 0)
	//{
		//m_Player->getHitBox()->setPosition(m_Player->getHitBox()->getPosition().x, m_Player->getHitBox()->getPosition().y);
	//	m_Player->changeNextState(FALL);
	//	return;
	//}
}

void PSRun::Render(RenderWindow* window)
{
	window->draw(*m_Animation);
}


void PSRun::Reset()
{

	m_Animation->Reset();
}

