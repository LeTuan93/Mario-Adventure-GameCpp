#include "Application.h"
#include "GameStateManager/GameStateBase.h"
Application::~Application()
{
	if (m_window!=nullptr) delete m_window;
}


void Application::Init()
{
	m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close);
    m_window->setFramerateLimit(60);
    m_window->setVerticalSyncEnabled(false);
    GameStateMachine::GetInstance()->ChangeState(StateTypes::INTRO);
    Wconnect->setWindow(m_window);
}   

//void Application::ResizeView()
//{
    //float aspecRatio = float(m_window->getSize().x) / float(m_window->getSize().y);
    //m_view.setSize(screenWidth * aspecRatio, screenHeight * aspecRatio);
//}
void Application::Run()
{
    Init();
    sf::Clock clock;
    float deltaTime = 0.f;
    while (m_window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window->close();
                break;
            case sf::Event::Resized:
                //ResizeView();
                //ResizeView(m_window, m_view);
                break;
            }
        }
        Update(deltaTime);
        //m_view.setCenter(m_Player.getHitBox()->getPosition());
        //m_window->setView(m_view);
        Render();
    }
}

void Application::Update(float deltaTime)
{
    if (GameStateMachine::GetInstance()->NeedToChangeState()) {
        GameStateMachine::GetInstance()->PerformStateChange();
    }
    GameStateMachine::GetInstance()->currentState()->Update(deltaTime);
    //Doing something
}

void Application::Render()
{
	m_window->clear(sf::Color::White);
	//draw something
    GameStateMachine::GetInstance()->currentState()->Render(m_window);
	m_window->display();
}


