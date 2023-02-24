#pragma once
#include"GameStateBase.h"
#include"../GameObjects/Player.h"
#include"../GameObjects/Layer.h"
#include "../GameObjects/CreepManager.h"
#include "../GameObjects/CollisionManager.h"
#include "../GameObjects/Tutorial_Map.h"
#include "../GameObjects/BlockCollisionManager.h"
#include "../GameObjects/CoinManager.h"
class GSPlay :public GameStateBase {
public:
    GSPlay();
    virtual ~GSPlay();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(sf::RenderWindow* window);
private:
    View playerView;
    Layer m_Layer;
    vector <Soil*> m_Soil;
    TutorialMap tutorialMap;
    Player m_Player;
    CollisionManager m_CollisionManager;
    CreepManager m_CreepManager;
    CoinManager m_CoinManager;
    int m_currentScore;
    float m_currentTime;
    Text m_Score;
    list<GameButton*> m_listBtn;
};  