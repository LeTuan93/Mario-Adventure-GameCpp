#pragma once
#include"GameStateBase.h"

class GSHighScore :public GameStateBase {
public:
    GSHighScore();
    virtual ~GSHighScore();

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
    list < Text*> m_listScore;

};