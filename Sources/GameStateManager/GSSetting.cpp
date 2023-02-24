#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
	for (auto it : m_listBtn)
	{
		if (it != nullptr)
			delete it;
	}
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
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


	//Turn on music
	button = new GameButton();
	button->Init("Yes");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {DATA->setAllowSound(true); });
	m_listBtn.push_back(button);


	//Turn off music
	button = new GameButton();
	button->Init("No");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {DATA->setAllowSound(false); });
	m_listBtn.push_back(button);

	//BackGround
	sf::Texture* texture = DATA->getTexture("BackGround layers/Background2");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);

	//Title game
	//m_Title.setString("Settings");
	//m_Title.setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
	//m_Title.setPosition(screenWidth / 2, screenHeight / 2);

}

void GSSetting::Update(float deltaTime)
{
	for (auto btn : m_listBtn) {
		btn->Update(deltaTime);
	}
}

void GSSetting::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_listBtn) {
		btn->Render(window);
	}
}
