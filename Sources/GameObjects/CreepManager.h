#pragma once
#include"../GameManager/ResourceManager.h"
#include "CreepBee.h"
#include "CreepBat.h"
#include "AngryPig.h"
#include "BlueBird.h"
#include "Bunny.h"
#include "Chameleon.h"
#include "Chicken.h"
#include "Mushroom.h"
#include "Ghost.h"
#include "Rino.h"
#include "Duck.h"
#include "Turtle.h"
#include "FatBird.h"
#include "AngryPigGreen.h"
#include "Plant.h"
#include "CollisionManager.h"
#include "cstdlib"
#include "ctime"
class CreepManager {
public:
	CreepManager();
	~CreepManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	void SpwanBee();
	void SpwanBat();
	void SpwanAngryPig();
	void SpwanBlueBird();
	void SpwanBunny();
	void SpwanChameleon();
	void SpwanChicken();
	void SpwanMushroom();
	void SpwanGhost();
	void SpwanRino();
	void SpwanDuck();
	void SpwanTurtle();
	void SpwanFatBird();
	void SpwanAngryPigGreen();
	void SpwanPlant();
	list<CreepBat*> m_listCreepBat;
	list<CreepBee*> m_listCreepBee;
	list<AngryPig*> m_listAngryPig;
	list<BlueBird*> m_listBlueBird;
	list<Bunny*> m_listBunny;
	list<Chameleon*> m_listChameleon;
	list<Chicken*> m_listChicken;
	list<Mushroom*> m_listMushroom;
	list<Ghost*> m_listGhost;
	list<Rino*> m_listRino;
	list<Duck*> m_listDuck;
	list<Turtle*> m_listTurtle;
	list<FatBird*> m_listFatBird;
	list<AngryPigGreen*> m_listAngryPigGreen;
	list<Plant*> m_listPlant;
	int m_CreepNumFatBird;
	int m_CreepNumGhost;
	int m_CreepNumRino;
	int m_CreepNumDuck;
	int m_CreepNumBlueBird;
	int m_CreepNumAngryPigGreen;
	float m_TimeSpwanCreep;
	float m_currentTime;
};