#pragma once
#include"../GameManager/ResourceManager.h"

class Layer {
public:
	void Init(std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	Sprite m_Image;

	Vector2i m_SizeImage;
};