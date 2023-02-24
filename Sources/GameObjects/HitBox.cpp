#include "HitBox.h"


HitBox::HitBox() {

}

HitBox::HitBox(Vector2i size) :RectangleShape((Vector2f)size)
{
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineThickness(1.f);
	this->setOutlineColor(sf::Color::Blue);
	m_Velocity = Vector2f(0, 0);
	m_isAlive = true;
}

HitBox::~HitBox()
{
}

void HitBox::Init(Vector2f velocity)
{
	m_Velocity=velocity;
}

sf::Vector2f HitBox::getVelocity()
{
	return m_Velocity;
}

void HitBox::setVelocity(Vector2f velocity)
{
	m_Velocity = velocity;
}
