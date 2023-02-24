#include "GameButton.h"

GameButton::GameButton()
{
	m_isHandling = false;
}

GameButton::~GameButton()
{
}

void GameButton::Init(string name)
{
	this->setTexture(DATA->getTexture("Button/" + name));
	this->setSize(sf::Vector2f(100, 100));
}

void GameButton::Update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		HandleToachEvent();
	}
}

void GameButton::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GameButton::HandleToachEvent()
{
	m_isHandling = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*Wconnect->getWindow())))
	{
		m_btnClickFunc();
		m_isHandling = true;
	}
}

void GameButton::isHandle()
{
}

void GameButton::setOnClick(void(*Func)())
{
	m_btnClickFunc = Func;
}
