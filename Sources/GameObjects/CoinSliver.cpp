#include "CoinSliver.h"

void CoinSliver::Init()
{
	m_HitBox = new HitBox(Vector2i(20, 20));
	m_HitBox->Init(sf::Vector2f(-200, 0));
	m_runCoin = new Animation(*DATA->getTexture("Gold/coinSliver"), Vector2i(4, 1), 0.1f);
	m_deathCoin = new Animation(*DATA->getTexture("Gold/death"), Vector2i(1, 1), 0.1f);
	m_deathCoin->setModeEndFrame(true);
	m_currentCoin = m_runCoin;
	m_HitBox->SetTag(COIN);
}