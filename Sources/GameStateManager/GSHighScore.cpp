#include "GSHighScore.h"

GSHighScore::GSHighScore()
{
}

GSHighScore::~GSHighScore()
{
	for (auto it : m_listBtn) {
		if (it != nullptr) {
			delete it;
		}
	}
	for (auto it : m_listScore) {
		if (it != nullptr) {
			delete it;
		}
	}
}

void GSHighScore::Exit()
{
}

void GSHighScore::Pause()
{
}

void GSHighScore::Resume()
{
}

void GSHighScore::Init()
{

	GameButton* button;

	//Back Button
	button = new GameButton();
	button->Init("Back");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 10);
	button->setOnClick([]() {GSM->PopState(); });
	m_listBtn.push_back(button);

	//BackGround
	sf::Texture* texture = DATA->getTexture("BackGround layers/HighScore");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);

	//Title game
	//m_Title.setString("Top Score");
	//m_Title.setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
	//m_Title.setPosition(screenWidth / 2-30, screenHeight / 2);
	
	//listScore
	for (int i = 0; i < ScoreManager::GetInstance()->getNum(); i++) {
		Text* t = new Text();
		t->setString(to_string(ScoreManager::GetInstance()->getHighScore()[i]));
		t->setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
		t->setPosition(screenWidth / 2-30, screenHeight / 2+40*(i+1)-60+7*i);
		m_listScore.push_back(t);
	}


}

void GSHighScore::Update(float deltaTime)
{
	for (auto btn : m_listBtn) {
		btn->Update(deltaTime);
	}
}

void GSHighScore::Render(sf::RenderWindow* window)
{
	//window->setView(playerView);
	window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_listBtn) {
		btn->Render(window);
	}
	for (auto it : m_listScore) {
		window->draw(*it);
	}
}
