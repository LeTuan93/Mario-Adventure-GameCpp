#pragma once
#include <map>
#include <string>
#include"../GameObjects/GameButton.h"
#include "../GameObjects/Animation.h"
#include"../GameConfig.h"
#include"SFML/Audio.hpp"
#include <list>
using namespace std;

#define DATA ResourceManager::GetInstance()

class ResourceManager :public CSingleton<ResourceManager>{
public:
    ResourceManager();
    ~ResourceManager();

    void addTexture(string name);
    void removeTexture(string name);
    Texture* getTexture(string name);

    void addFont(string name);
    void removeFont(string name);
    Font* getFont(string name);

    void addSound(string name);
    void removeSound(string name);
    Sound* getSound(string name);

    void addMusic(string name);
    void removeMusic(string name);
    Music* getMusic(string name);

    void playMusic(string name);
    void playSound(string name);
    void setAllowSound(bool allow);
private:
    map<string,Texture*> m_MapTexture;
    map<string,Font*> m_MapFont;
    map<string, Sound*> m_MapSound;
    map<string, Music*> m_MapMusic;
    string m_Path;
    string m_TexturePath;
    string m_FontPath;
    string m_SoundPath;

    bool m_allowSound;
};