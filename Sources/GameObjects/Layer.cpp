#include "Layer.h"

void Layer::Init(string name)
{
	Texture* texture = DATA->getTexture(name);
	m_Image.setTexture(*texture);
	m_SizeImage = (sf::Vector2i)texture->getSize();
}

void Layer::Update(float deltaTime)
{

}

void Layer::Render(sf::RenderWindow* window)
{
	window->draw(m_Image);
}
