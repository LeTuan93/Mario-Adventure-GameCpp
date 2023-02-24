#pragma once
#include"GameStateManager/GameStateMachine.h"
#include"GameManager/ResourceManager.h"

class Application{
public:
	void Run();
	~Application();
private:
	void Init();
	void Update(float m_deltatime);
	void Render();
	void ResizeView();
private:
	sf::RenderWindow* m_window;
};