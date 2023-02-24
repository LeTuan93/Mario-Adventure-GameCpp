#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
	for (auto it : m_listBtn)
	{
		if (it != nullptr)
			delete it;
	}
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	playerView = View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight));
	GameButton* button;

	//Replay Button
	button = new GameButton();
	button->Init("Replay");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth /2 + screenWidth / 12, screenHeight - screenHeight / 8-100);
	button->setOnClick([]() {
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
	});
	m_listBtn.push_back(button);
	//Back Button
	button = new GameButton();
	button->Init("Back");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8-100);
	button->setOnClick([]() {
		GSM->PopState(); 
		GSM->PopState();
		GSM->PopState();
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
	});
	m_listBtn.push_back(button);

	//BackGround LOSE
	Texture* texture = DATA->getTexture("BackGround layers/Lose");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);

	//Title game
	//m_Title.setString("Game Over!");
	//m_Title.setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
	//m_Title.setPosition(screenWidth / 2-100, screenHeight / 2);

	//Best Score
	m_bestScore.setString(to_string(ScoreManager::GetInstance()->getBestScore()));
	m_bestScore.setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
	m_bestScore.setPosition(screenWidth / 2+30, screenHeight / 2 -67);


	//Your Score
	m_currentScore.setString(to_string(ScoreManager::GetInstance()->getCurrentScore()));
	m_currentScore.setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
	m_currentScore.setPosition(screenWidth / 2+30, screenHeight / 2 -5);
}

void GSEnd::Update(float deltaTime)
{
	for (auto btn : m_listBtn) {
		btn->Update(deltaTime);
	}
	
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->setView(playerView);
	window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_listBtn) {
		btn->Render(window);
	}
	window->draw(m_bestScore);
	window->draw(m_currentScore);
}
