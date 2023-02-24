#pragma once
#include "../GameManager/ResourceManager.h"
#include <vector>
#include <iostream>
#include <cstring>
#include "Soil.h"
class TutorialMap {
private:
	vector <vector<int>> map_ID;
	vector <vector<Soil*>> tutorial_map;
	vector <Soil*> m_Soil;
public:
	TutorialMap();
	~TutorialMap();
	void Init();
	vector <Soil*> getSoil();
};