#pragma once
#include"GameStateBase.h"
class GSEnd :public GameStateBase {
public:
    GSEnd();
    virtual ~GSEnd();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(sf::RenderWindow* window);
private:
  
    View playerView;
    Sprite m_Background;
    Text m_Title;
    list<GameButton*> m_listBtn;
    Text m_currentScore;
    Text m_bestScore;

};