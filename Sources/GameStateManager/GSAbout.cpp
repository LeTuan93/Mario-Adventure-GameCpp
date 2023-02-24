#include "GSAbout.h"
#include <windows.h>
#include <shellapi.h>
GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
	for (auto it : m_listBtn)
	{
		if (it != nullptr)
			delete it;
	}
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
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
	sf::Texture* texture = DATA->getTexture("BackGround layers/About");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);

}


void GSAbout::Update(float deltaTime)
{
	for (auto btn : m_listBtn) {
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_listBtn) {
		btn->Render(window);
	}

}
