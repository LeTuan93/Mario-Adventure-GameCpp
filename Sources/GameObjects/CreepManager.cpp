#include "CreepManager.h"
CreepManager::CreepManager()
{
	m_CreepNumGhost = 3;
	m_CreepNumRino = 2;
	m_CreepNumDuck = 5;
	m_CreepNumFatBird = 10;
	m_CreepNumBlueBird = 10;
	m_CreepNumAngryPigGreen = 2;
	m_TimeSpwanCreep = 2.f;
	m_currentTime = 0.f;
	srand(time(NULL));
}
CreepManager::~CreepManager()
{
	for (auto it : m_listCreepBee) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listCreepBee.clear();

	for (auto it : m_listCreepBat) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listCreepBat.clear();

	for (auto it : m_listAngryPig) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listAngryPig.clear();

	for (auto it : m_listBlueBird) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listBlueBird.clear();

	for (auto it : m_listBunny) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listBunny.clear();

	for (auto it : m_listChameleon) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listChameleon.clear();

	for (auto it : m_listChicken) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listChicken.clear();

	for (auto it : m_listMushroom) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listMushroom.clear();

	for (auto it : m_listGhost) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listGhost.clear();

	for (auto it : m_listRino) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listRino.clear();

	for (auto it : m_listDuck) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listDuck.clear();
	
	for (auto it : m_listTurtle) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listTurtle.clear();

	for (auto it : m_listFatBird) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listFatBird.clear();

	for (auto it : m_listAngryPigGreen) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listAngryPigGreen.clear();

	for (auto it : m_listPlant) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listPlant.clear();
}
void CreepManager::Init(CollisionManager &collisionManager)
{
		CreepBee* creepBee = new CreepBee();
		creepBee->Init();
		creepBee->getHitBox()->setAlive(false);
		m_listCreepBee.push_back(creepBee);
		collisionManager.addObj(creepBee->getHitBox());

		CreepBat* creepBat = new CreepBat();
		creepBat->Init();
		creepBat->getHitBox()->setAlive(false);
		m_listCreepBat.push_back(creepBat);
		collisionManager.addObj(creepBat->getHitBox());

		AngryPig* angryPig = new AngryPig();
		angryPig->Init();
		angryPig->getHitBox()->setAlive(false);
		m_listAngryPig.push_back(angryPig);
		collisionManager.addObj(angryPig->getHitBox());

		Bunny* bunny = new Bunny();
		bunny->Init();
		bunny->getHitBox()->setAlive(false);
		m_listBunny.push_back(bunny);
		collisionManager.addObj(bunny->getHitBox());

		Chameleon* chameleon = new Chameleon();
		chameleon->Init();
		chameleon->getHitBox()->setAlive(false);
		m_listChameleon.push_back(chameleon);
		collisionManager.addObj(chameleon->getHitBox());

		Chicken* chicken = new Chicken();
		chicken->Init();
		chicken->getHitBox()->setAlive(false);
		m_listChicken.push_back(chicken);
		collisionManager.addObj(chicken->getHitBox());

		Mushroom* mushroom = new Mushroom();
		mushroom->Init();
		mushroom->getHitBox()->setAlive(false);
		m_listMushroom.push_back(mushroom);
		collisionManager.addObj(mushroom->getHitBox());

		Turtle* turtle = new Turtle();
		turtle->Init();
		turtle->getHitBox()->setAlive(false);
		m_listTurtle.push_back(turtle);
		collisionManager.addObj(turtle->getHitBox());

		Plant* plant = new Plant();
		plant->Init();
		plant->getHitBox()->setAlive(false);
		m_listPlant.push_back(plant);
		collisionManager.addObj(plant->getHitBox());
	
		for (int i = 0; i < m_CreepNumGhost; i++) {
			Ghost* ghost = new Ghost();
			ghost->Init();
			ghost->getHitBox()->setAlive(false);
			m_listGhost.push_back(ghost);
			collisionManager.addObj(ghost->getHitBox());
		}

		for (int i = 0; i < m_CreepNumRino; i++) {
			Rino* rino = new Rino();
			rino->Init();
			rino->getHitBox()->setAlive(false);
			m_listRino.push_back(rino);
			collisionManager.addObj(rino->getHitBox());
		}

		for (int i = 0; i < m_CreepNumDuck; i++) {
			Duck* duck = new Duck();
			duck->Init();
			duck->getHitBox()->setAlive(false);
			m_listDuck.push_back(duck);
			collisionManager.addObj(duck->getHitBox());
		}

		for (int i = 0; i < m_CreepNumFatBird; i++) {
			FatBird* fatBird = new FatBird();
			fatBird->Init();
			fatBird->getHitBox()->setAlive(false);
			m_listFatBird.push_back(fatBird);
			collisionManager.addObj(fatBird->getHitBox());
		}
		for (int i = 0; i < m_CreepNumBlueBird; i++) {
			BlueBird* blueBird = new BlueBird();
			blueBird->Init();
			blueBird->getHitBox()->setAlive(false);
			m_listBlueBird.push_back(blueBird);
			collisionManager.addObj(blueBird->getHitBox());
		}

		for (int i = 0; i < m_CreepNumAngryPigGreen; i++) {
			AngryPigGreen* angryPigGreen = new AngryPigGreen();
			angryPigGreen->Init();
			angryPigGreen->getHitBox()->setAlive(false);
			m_listAngryPigGreen.push_back(angryPigGreen);
			collisionManager.addObj(angryPigGreen->getHitBox());
		}
}

void CreepManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > m_TimeSpwanCreep) {
		SpwanBee();
		SpwanBat();
		SpwanAngryPig();
		SpwanBlueBird();
		SpwanBunny();
		SpwanChameleon();
		SpwanChicken();
		SpwanMushroom();
		SpwanGhost();
		SpwanRino();
		SpwanDuck();
		SpwanTurtle();
		SpwanFatBird();
		SpwanAngryPigGreen();
		SpwanPlant();
		m_currentTime = 0.f;
	}
	for (auto creep : m_listCreepBee) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listCreepBat) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listAngryPig) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listBlueBird) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listBunny) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listChameleon) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listChicken) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listMushroom) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listGhost) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listRino) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listDuck) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listTurtle) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listFatBird) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listAngryPigGreen) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_listPlant) {
		creep->Update(deltaTime);
	}
}

void CreepManager::Render(sf::RenderWindow* window)
{
	for (auto creep : m_listCreepBee) {
		creep->Render(window);
	}
	for (auto creep : m_listCreepBat) {
		creep->Render(window);
	}
	for (auto creep : m_listAngryPig) {
		creep->Render(window);
	}
	for (auto creep : m_listBlueBird) {
		creep->Render(window);
	}
	for (auto creep : m_listBunny) {
		creep->Render(window);
	}
	for (auto creep : m_listChameleon) {
		creep->Render(window);
	}
	for (auto creep : m_listChicken) {
		creep->Render(window);
	}
	for (auto creep : m_listMushroom) {
		creep->Render(window);
	}
	for (auto creep : m_listGhost) {
		creep->Render(window);
	}
	for (auto creep : m_listRino) {
		creep->Render(window);
	}
	for (auto creep : m_listDuck) {
		creep->Render(window);
	}
	for (auto creep : m_listTurtle) {
		creep->Render(window);
	}
	for (auto creep : m_listFatBird) {
		creep->Render(window);
	}
	for (auto creep : m_listAngryPigGreen) {
		creep->Render(window);
	}
	for (auto creep : m_listPlant) {
		creep->Render(window);
	}
}

void CreepManager::SpwanBee()
{
	Creep* creep = nullptr;
	for (auto it : m_listCreepBee) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(700,450));
	creep->setStartRange(Vector2f(200, 700));
	creep->getHitBox()->setVelocity(Vector2f(50 , 0));
	creep->Reset();
}

void CreepManager::SpwanBat()
{
	Creep* creep = nullptr;
	for (auto it : m_listCreepBat) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(2300, 580));
	creep->setStartRange(Vector2f(2050, 2300));
	creep->Reset();
}

void CreepManager::SpwanAngryPig()
{
	Creep* creep = nullptr;
	for (auto it : m_listAngryPig) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(870,450));
	creep->setStartRange(Vector2f(750, 870));
	creep->Reset();
}

void CreepManager::SpwanBlueBird()
{
	Creep* creep = nullptr;
	for (auto it : m_listBlueBird) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	//creep->getHitBox()->Init(Vector2f(-50, 0));
	creep->setStartPoint(Vector2f(5200 + rand() % 1000, 200+rand()%350));
	creep->setStartRange(Vector2f(4700 + rand() % 500, 6200 - rand() % 600));
	creep->Reset();
}

void CreepManager::SpwanBunny()
{
	Creep* creep = nullptr;
	for (auto it : m_listBunny) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(2690, 255));
	creep->setStartRange(Vector2f(2550, 2670));
	creep->Reset();
}

void CreepManager::SpwanChameleon()
{
	Creep* creep = nullptr;
	for (auto it : m_listChameleon) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(2450, 110));
	creep->setStartRange(Vector2f(2300, 2450));
	creep->Reset();
}

void CreepManager::SpwanChicken()
{
	Creep* creep = nullptr;
	for (auto it : m_listChicken) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(1430, 400));
	creep->setStartRange(Vector2f(1100, 1430));
	creep->Reset();
}

void CreepManager::SpwanMushroom()
{
	Creep* creep = nullptr;
	for (auto it : m_listMushroom) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->setStartPoint(Vector2f(3300, 450));
	creep->setStartRange(Vector2f(3300, 3300));
	creep->Reset();
}

void CreepManager::SpwanGhost()
{
	Creep* creep = nullptr;
	for (auto it : m_listGhost) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(3500+rand()%200, 450));
	creep->setStartRange(Vector2f(3000+rand()%300, 4500-rand()%100));
	creep->Reset();
}

void CreepManager::SpwanRino()
{
	Creep* creep = nullptr;
	for (auto it : m_listRino) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(6200 + rand() % 200, 455));
	creep->setStartRange(Vector2f(6200 + rand() % 100, 7000 - rand() % 100));
	creep->Reset();
}

void CreepManager::SpwanDuck()
{
	Creep* creep = nullptr;
	for (auto it : m_listDuck) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(8000 + rand() % 200, 500));
	creep->setStartRange(Vector2f(8000 - rand() % 400, 8000 + rand() % 300));
	creep->Reset();
}

void CreepManager::SpwanTurtle()
{
	Creep* creep = nullptr;
	for (auto it : m_listTurtle) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(2300, 420));
	creep->setStartRange(Vector2f(2220, 2320));
	creep->Reset();
}

void CreepManager::SpwanFatBird()
{
	Creep* creep = nullptr;
	for (auto it : m_listFatBird) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(7500 + rand() % 800, 650));
	creep->setStartRange(Vector2f(0, 700));
	creep->Reset();
}

void CreepManager::SpwanAngryPigGreen()
{
	Creep* creep = nullptr;
	for (auto it : m_listAngryPigGreen) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(9000 +rand() % 800, 450));
	creep->setStartRange(Vector2f(9000+rand()%500, 10000-rand()%200));
	creep->Reset();
}

void CreepManager::SpwanPlant()
{
	Creep* creep = nullptr;
	for (auto it : m_listPlant) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(Vector2f(11200 , 450));
	creep->setStartRange(Vector2f(11200 , 11300));
	creep->Reset();
}
