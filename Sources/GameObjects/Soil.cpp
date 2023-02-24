#include "Soil.h"

Soil::Soil() {

}

Soil::Soil(Vector2f size,Vector2f position) {
	m_HitBox.setOrigin(size / 2.f);
	m_HitBox.setSize(size);
	m_HitBox.setPosition(position);
	m_HitBox.setOutlineThickness(1.f);
	m_HitBox.setOutlineColor(Color::Red);
}

Soil::~Soil() {
}

void Soil::Render(RenderWindow* window) {
	window->draw(m_HitBox);
}