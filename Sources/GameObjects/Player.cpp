#include "Player.h"
#include "PSRun.h"
#include "PSJump.h"
#include "PSFall.h"
#include "PSDeath.h"
#include"PSAttack.h"
#include "PSStand.h"
Player::Player()
{
	m_nextState = IPState::SNULL;
	m_standState = new PSStand(this);
	m_runState = new PSRun(this);
	m_jumpState = new PSJump(this);
	m_fallState = new PSFall(this);
	m_deathState = new PSDeath(this);
	m_attackState = new PSAttack(this);
	m_currentState = m_standState;
}

Player::~Player()
{
	if (m_standState != nullptr) {
		delete m_standState;
	}
	if (m_runState != nullptr) {
		delete m_runState;
	}
	if (m_jumpState != nullptr) {
		delete m_jumpState;
	}
	if (m_fallState != nullptr) {
		delete m_fallState;
	}
	if (m_deathState != nullptr) {
		delete m_deathState;
	}
	if (m_attackState != nullptr) {
		delete m_attackState;
	}
	m_currentState = nullptr;

}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

void Player::Init()
{
	m_standState->Init();
	m_runState->Init();
	m_jumpState->Init();
	m_fallState->Init();
	m_deathState->Init();
	m_attackState->Init();
	
	m_HitBox = new HitBox(Vector2i(32, 32));
	m_HitBox->setPosition(30, 450);
	m_HitBox->Init(sf::Vector2f(200, 300));
	m_HitBox->SetTag(PLAYER);


}

void Player::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime);
}

void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	//window->draw(*m_HitBox);
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}


void Player::performStateChange()
{
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState)
		{
		case IPState::STAND:
			m_currentState = m_standState;
			break;
		case IPState::RUN:
			m_currentState = m_runState;
			break;
		case IPState::JUMP:
			m_currentState = m_jumpState;
			break;
		case IPState::FALL:
			m_currentState = m_fallState;
			break;
		case IPState::ATTACK:
			m_currentState = m_attackState;
			break;
		case IPState::DEATH:
			m_currentState = m_deathState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		
	}
}

