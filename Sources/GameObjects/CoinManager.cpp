#include "CoinManager.h"
CoinManager::CoinManager()
{
	m_numCoinGoldBig = 50;
	m_numCoinSliver = 100;
	m_numCoinGoldSmall = 300;
	m_TimeSpwanCoin = 2.f;
	m_currentTime = 0.f;
	srand(time(NULL));
}
CoinManager::~CoinManager()
{
	for (auto it : m_listCoinGoldBig) {
		if (it != nullptr) {
			delete it;
		}
	}

	for (auto it : m_listCoinSliver) {
		if (it != nullptr) {
			delete it;
		}
	}

	for (auto it : m_listCoinGoldSmall) {
		if (it != nullptr) {
			delete it;
		}
	}
}
void CoinManager::Init(CollisionManager& collisionManager)
{
	for (int i = 0; i < m_numCoinGoldBig; i++) {
		CoinGoldBig* coin = new CoinGoldBig();
		coin->Init();
		coin->getHitBox()->setAlive(false);
		m_listCoinGoldBig.push_back(coin);
		collisionManager.addObj(coin->getHitBox());
	}

	for (int i = 0; i < m_numCoinSliver; i++) {
		CoinSliver* coin = new CoinSliver();
		coin->Init();
		coin->getHitBox()->setAlive(false);
		m_listCoinSliver.push_back(coin);
		collisionManager.addObj(coin->getHitBox());
	}

	for (int i = 0; i < m_numCoinGoldSmall; i++) {
		CoinGoldSmall* coin = new CoinGoldSmall();
		coin->Init();
		coin->getHitBox()->setAlive(false);
		m_listCoinGoldSmall.push_back(coin);
		collisionManager.addObj(coin->getHitBox());
	}
}

void CoinManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > m_TimeSpwanCoin) {
		SpwanCoinGoldBig();
		SpwanCoinSliver();
		SpwanCoinGoldSmall();
		m_currentTime = 0.f;
	}
	for (auto coin : m_listCoinGoldBig) {
		coin->Update(deltaTime);
	}
	for (auto coin : m_listCoinSliver) {
		coin->Update(deltaTime);
	}
	for (auto coin : m_listCoinGoldSmall) {
		coin->Update(deltaTime);
	}
}

void CoinManager::Render(sf::RenderWindow* window)
{
	for (auto coin : m_listCoinGoldBig) {
		coin->Render(window);
	}
	for (auto coin : m_listCoinSliver) {
		coin->Render(window);
	}
	for (auto coin : m_listCoinGoldSmall) {
		coin->Render(window);
	}
}

void CoinManager::SpwanCoinGoldBig()
{
	CoinGoldBig* coin = nullptr;
	for (auto it : m_listCoinGoldBig) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			coin = it;
			break;
		}
	}
	if (coin == nullptr) return;
	coin->getHitBox()->setAlive(true);
	coin->setStartPoint(Vector2f(0+rand()%11000, 660-rand()%500));
	coin->getHitBox()->setVelocity(Vector2f(200, 0));
	coin->Reset();
}

void CoinManager::SpwanCoinSliver()
{
	CoinSliver* coin = nullptr;
	for (auto it : m_listCoinSliver) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			coin = it;
			break;
		}
	}
	if (coin == nullptr) return;
	coin->getHitBox()->setAlive(true);
	coin->setStartPoint(Vector2f(0 + rand() % 11000, 660 - rand() % 500));
	coin->getHitBox()->setVelocity(Vector2f(200, 0));
	coin->Reset();
}

void CoinManager::SpwanCoinGoldSmall()
{
	CoinGoldSmall* coin = nullptr;
	for (auto it : m_listCoinGoldSmall) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			coin = it;
			break;
		}
	}
	if (coin == nullptr) return;
	coin->getHitBox()->setAlive(true);
	coin->setStartPoint(Vector2f(0 + rand() % 11000, 660 - rand() % 500));
	coin->getHitBox()->setVelocity(Vector2f(200, 0));
	coin->Reset();
}

