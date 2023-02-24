#pragma once
#include"GameStateBase.h"

class GSMenu :public GameStateBase {
public:
    GSMenu();
    virtual ~GSMenu();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(sf::RenderWindow* window);
    
    void frameInit();
    void fbInit();
private:

    list<GameButton*> m_listBtn;
    Sprite m_Background;
    View playerView;

    Text m_Title;
    Text* nameOwner;
    Sprite logoFb;
    Text* linkFb;
    RectangleShape clickFb;
    Text name;
    Text dob;

    float time = 0.5f;

};