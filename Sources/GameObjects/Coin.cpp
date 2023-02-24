#include "Coin.h"

Coin::Coin()
{
	m_stop = true;
	m_soundEatGold = false;
}

Coin::~Coin()
{
	m_currentCoin = nullptr;
	if (m_deathCoin != nullptr) {
		delete m_deathCoin;
	}
	if (m_runCoin != nullptr) {
		delete m_runCoin;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
	}
}

void Coin::Init()
{
}

void Coin::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_HitBox->isAlive()) {
		m_currentCoin->Update(deltaTime);
		m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		if (m_HitBox->getPosition().x <= getStartPoint().x) {
			m_currentCoin->setScale(-1, 1);
			m_HitBox->Init(Vector2f(100, 0));
		}
		else  if (m_HitBox->getPosition().x > getStartPoint().y)
		{
			m_currentCoin->setScale(1, 1);
			m_HitBox->Init(Vector2f(-100, 0));
		}
		m_currentCoin->setPosition(getHitBox()->getPosition());
	}
	else
	{
		if (m_soundEatGold == false) {
			DATA->getSound("Mario an tien")->play();
			m_soundEatGold = true;
		}
		m_currentCoin = m_deathCoin;
		if (m_currentCoin->getCurrentFrame().x != m_currentCoin->getFrameNum().x - 1) {
			m_currentCoin->Update(deltaTime);
			m_currentCoin->setPosition(getHitBox()->getPosition());
		}
		else m_stop = true;

	}

}

void Coin::Render(sf::RenderWindow* window)
{
	if (m_stop) return;
	window->draw(*m_currentCoin);
	//window->draw(*m_HitBox);
}

void Coin::Reset()
{
	m_stop = false;
	m_deathCoin->Reset();
	m_runCoin->Reset();
	m_currentCoin = m_runCoin;
	m_HitBox->setPosition(m_startPoint);
	m_soundEatGold = false;
}
