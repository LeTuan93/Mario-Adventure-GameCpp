#pragma once
#include"../GameManager/ResourceManager.h"
#include "CoinGoldBig.h"
#include "CoinSliver.h"
#include "CoinGoldSmall.h"
#include "Coin.h"
#include "CollisionManager.h"
#include "cstdlib"
#include "ctime"
class CoinManager {
public:
	CoinManager();
	~CoinManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	void SpwanCoinGoldBig();
	void SpwanCoinSliver();
	void SpwanCoinGoldSmall();
	list<CoinGoldBig*> m_listCoinGoldBig;
	list<CoinSliver*> m_listCoinSliver;
	list<CoinGoldSmall*> m_listCoinGoldSmall;
	int m_numCoinGoldBig;
	int m_numCoinSliver;
	int m_numCoinGoldSmall;
	float m_TimeSpwanCoin;
	float m_currentTime;
};