#pragma once
#include<SFML/Graphics.hpp>
#include"../GameConfig.h"
using namespace sf;
class Animation : public sf::Sprite {
public:
	Animation(Texture& texture, Vector2i frameNum, float frameTime);
	void CalculateRectSize();
	void CalculateRectUV();
	void ApplyRect();
	void Update(float deltatime);
	void Reset();

	void setModeEndFrame(bool stop);

	Vector2i getFrameNum() { return m_frameNum; }
	Vector2i getCurrentFrame() { return m_currentFrame; }
private:
	Vector2i m_frameNum;
	Vector2i m_currentFrame;

	float m_frameTime;
	float m_currentTime;

	Vector2i m_rectUV;
	Vector2i m_rectSize;
	IntRect m_rect;

	bool m_modeStopAtEndFrame;


};