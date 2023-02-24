#pragma once
#include"GameStateBase.h"

class GSAbout :public GameStateBase {
public:
    GSAbout();
    virtual ~GSAbout();

    void Exit();
    void Pause();
    void Resume();

    void Init();

    void Update(float deltaTime);
    void Render(sf::RenderWindow* window);
private:
    Sprite m_Background;
    Text m_Title;
    list<GameButton*> m_listBtn;


};