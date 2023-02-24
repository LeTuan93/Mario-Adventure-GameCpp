#include "GSPlay.h"
GSPlay::GSPlay()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{

	//Pause Button
	GameButton* button;

	button = new GameButton();
	button->Init("Pause");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(70,70));
	button->setPosition(1100, 80);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::PAUSE); });
	m_listBtn.push_back(button);

	playerView = View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight));
	printf("Play Game");
	tutorialMap.Init();
	m_Player.Init();
	m_Layer.Init("map1");
	m_CollisionManager.addObj(m_Player.getHitBox());
	m_CreepManager.Init(m_CollisionManager);
	m_CoinManager.Init(m_CollisionManager);
	m_Score.setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
	m_Score.setString("0");
	m_Score.setFillColor(Color::White);
	m_Score.setPosition(50, 50);

	DATA->playMusic("GameStart");
	DATA->getMusic("GameStart")->setLoop(true);
	DATA->getMusic("GameStart")->setVolume(30);
	
}

void GSPlay::Update(float deltaTime)
{

	if (m_Player.getHitBox()->isAlive()) {
		m_currentTime += deltaTime;
		if (m_currentTime >= 0.5f) {
			m_currentScore++;
			m_Score.setString(to_string(m_currentScore));
			m_currentTime -= 1.f;
		}
		m_Soil = tutorialMap.getSoil();
		bool checkFall = false;
		for (auto soil : m_Soil) {
			soil->GetBlockCollider().CheckBlockCollider(m_Player.GetBlockCollider());
			if (soil->GetBlockCollider().CheckBlockCollider(m_Player.GetBlockCollider())) {
				checkFall = true;
			}
		}
		if (checkFall == false && m_Player.checkFall == 0)
		{
			m_Player.resetCollision();
			checkFall = true;
			m_Player.checkFall = 1;
		}
	}
	else ScoreManager::GetInstance()->setCurrentScore(m_currentScore);

	m_Player.Update(deltaTime);
	if (m_Player.getHitBox()->isAlive()) {
		m_CreepManager.Update(deltaTime);
		m_CoinManager.Update(deltaTime);
		m_CollisionManager.Update();
	}
	if (m_Player.getHitBox()->getPosition().x - screenWidth / 2 <= 0) {
		playerView.setCenter(screenWidth / 2, screenHeight / 2);
	}
	else if (m_Player.getHitBox()->getPosition().x + screenWidth / 2 >= mapWidth) {
		playerView.setCenter(screenWidth - screenWidth / 2, screenHeight / 2);
	}
	else playerView.setCenter(m_Player.getHitBox()->getPosition().x, screenHeight / 2);

	for (auto button : m_listBtn) {
		button->Update(deltaTime);
	}
	if (m_Player.getHitBox()->getPosition().x >= 11000) {
		GameStateMachine::GetInstance()->ChangeState(ENDWIN);
	}
}

void GSPlay::Render(sf::RenderWindow* window)
{
	window->setView(playerView);
	m_Layer.Render(window);
	m_Player.Render(window);
	m_CreepManager.Render(window);
	m_CoinManager.Render(window);
	window->draw(m_Score);
	for (auto button : m_listBtn) {
		button->Render(window);
	}
	window->setView(playerView);
}
