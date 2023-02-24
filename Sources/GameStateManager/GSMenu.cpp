#include "GSMenu.h"
#include <windows.h>
#include <shellapi.h>
GSMenu::GSMenu()
{
	m_Title = Text();
	nameOwner = new Text();
	linkFb = new Text();
}

GSMenu::~GSMenu()
{
	if (nameOwner != nullptr)
		delete nameOwner;
	if (linkFb != nullptr)
		delete linkFb;
	for (auto it : m_listBtn)
	{
		if (it != nullptr)
			delete it;
	}
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	ScoreManager::GetInstance()->readFile();

}

void GSMenu::Init()
{
	playerView = View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight));
	printf("Start  ");
	GameButton* button;

	//Play Button
	button = new GameButton();
	button->Init("Play");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::PLAY); });
	button->setPosition(screenWidth / 2, screenHeight / 2+50);
	button->setSize(sf::Vector2f(150, 150));
	button->setOrigin(button->getSize() / 2.f);
	m_listBtn.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("Close");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8-100);
	button->setOnClick([]() {Wconnect->getWindow()->close(); });
	m_listBtn.push_back(button);
	

	//Setting Button
	button = new GameButton();
	button->Init("Option");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8-100);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SETTING); });
	m_listBtn.push_back(button);

	//Leaderboard Button
	button = new GameButton();
	button->Init("Leaderboard");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8-100);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::HIGHSCORE); });
	m_listBtn.push_back(button);

	//About Button
	button = new GameButton();
	button->Init("About");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8-100);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::ABOUT); });
	m_listBtn.push_back(button);

	//BackGround
	Texture* texture = DATA->getTexture("BackGround layers/Background2");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);

	//	Name
	name.setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
	name.setString("Author: Le Anh Tuan");
	name.setFillColor(sf::Color(253, 127, 33));
	name.setCharacterSize(32);
	name.setOutlineThickness(1.f);
	name.setOutlineColor(sf::Color::White);
	name.setOrigin(m_Title.getGlobalBounds().width / 2.f-450, m_Title.getGlobalBounds().height / 2.f-300);
	name.setPosition(screenWidth / 3 + 20, screenHeight / 4 + 80);
	this->frameInit();
	this->fbInit();

}

void GSMenu::Update(float deltaTime)
{
	for (auto btn : m_listBtn) {
		btn->Update(deltaTime);
	}
	if (time > 0.0f)
	{
		time -= deltaTime;
	}

	for (auto btn : m_listBtn)
	{
		btn->Update(deltaTime);
	}

	//	Facebook
	if (clickFb.getGlobalBounds().contains(Vector2f(Mouse::getPosition(*Wconnect->getWindow()))))
	{
		linkFb->setFillColor(sf::Color(242, 254, 6));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && time <= 0.0f)
		{
			ShellExecute(0, 0, L"https://www.facebook.com/tuan.kinh.737", 0, 0, SW_SHOW);
			time = 0.5f;
		}
	}
	else
	{
		linkFb->setFillColor(sf::Color(219, 49, 14));
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->setView(playerView);
	window->draw(m_Background);

	window->draw(logoFb);
	window->draw(*linkFb);
	window->draw(clickFb);
	window->draw(name);

	for (auto btn : m_listBtn) {
		btn->Render(window);
	}
}

void GSMenu::frameInit()
{
}

void GSMenu::fbInit()
{
	sf::Texture* texture;

	//	Click
	clickFb.setSize(sf::Vector2f(200.f, 53.f));
	clickFb.setOrigin(clickFb.getSize() / 2.f);
	clickFb.setPosition(sf::Vector2f(screenWidth / 2 + 400, screenHeight / 2 + 280));
	clickFb.setFillColor(sf::Color(0, 0, 0, 0));
	//clickFb.setFillColor(sf::Color::Green);

	//	Logo
	texture = DATA->getTexture("btn/logofb");
	logoFb.setTexture(*texture);
	logoFb.setScale(sf::Vector2f(0.5f, 0.5f));
	logoFb.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	logoFb.setPosition(screenWidth / 2 +300, screenHeight / 2 + 280);

	//	link
	linkFb->setFont(*DATA->getFont("HalloweenSlimePersonalUse-4B80D"));
	linkFb->setString("Le Tuan");
	linkFb->setFillColor(sf::Color(219, 49, 14));
	linkFb->setCharacterSize(40);
	linkFb->setOrigin(m_Title.getGlobalBounds().width / 2.f-350, m_Title.getGlobalBounds().height / 2.f-200);
	linkFb->setPosition(screenWidth / 2 + 20, screenHeight / 2 + 60);
}

