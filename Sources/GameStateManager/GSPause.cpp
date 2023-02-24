#include "GSPause.h"

GSPause::GSPause()
{
}

GSPause::~GSPause()
{
}

void GSPause::Exit()
{
}

void GSPause::Pause()
{
}

void GSPause::Resume()
{
}

void GSPause::Init()
{
	playerView = View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight));
	m_waitPause = 0.2f;
	m_currentPauseTime = 0.f;
	m_canPause = false;
	GameButton* button;

	//Continue Play
	button = new GameButton();
	button->Init("Play");
	button->setOnClick([]() {GameStateMachine::GetInstance()->ChangeState(PLAY); });
	button->setSize(Vector2f(100, 100));
	button->setPosition(screenWidth / 2 -250, screenHeight/2+40);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("Option");
	button->setOnClick([]() {GameStateMachine::GetInstance()->ChangeState(SETTING); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 -100, screenHeight / 2+40);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);

	//About Button
	button = new GameButton();
	button->Init("About");
	button->setOnClick([]() {GameStateMachine::GetInstance()->ChangeState(ABOUT); });
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + 85, screenHeight / 2 + 40);
	button->setOrigin(button->getSize() / 2.f);
	m_listButton.push_back(button);


	//Back Button
	button = new GameButton();
	button->Init("Back");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + 250,screenHeight / 2 + 40);
	button->setOnClick([]() {
		GSM->PopState();
		GSM->PopState(); 
	});
	m_listButton.push_back(button);
	//BackGround
	Texture* texture = DATA->getTexture("BackGround layers/Pause");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);

}

void GSPause::Update(float deltaTime)
{
	m_currentPauseTime += deltaTime;
	if (m_currentPauseTime >= m_waitPause) {
		m_canPause = true;
	}
	//if (Keyboard::isKeyPressed(Keyboard::P) && m_canPause) {
	//	GSM->PopState();
	//}
	for (auto button : m_listButton) {
		button->Update(deltaTime);
	}
}

void GSPause::Render(sf::RenderWindow* window)
{
	window->setView(playerView);
	window->draw(m_Background);
	for (auto button : m_listButton) {
		button->Render(window);
	}
}