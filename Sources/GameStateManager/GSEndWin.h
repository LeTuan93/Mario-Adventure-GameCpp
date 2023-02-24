#pragma once
#include"GameStateBase.h"
class GSEndWin :public GameStateBase {
public:
    GSEndWin();
    virtual ~GSEndWin();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(sf::RenderWindow* window);
private:

    //Player m_Player;
    View playerView;
    Sprite m_Background;
    Text m_Title;
    list<GameButton*> m_listBtn;
    Text m_currentScore;
    Text m_bestScore;

};