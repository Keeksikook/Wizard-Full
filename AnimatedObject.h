#pragma once
#include"SFML/Graphics.hpp"
#include"AssetManager.h"

class AnimatedObject
{
private:
	sf::Clock c_fromLastSwitch;
	sf::Sprite sprite;
	unsigned frameCount;
	AssetManager& manager;

	//As seconds
	float duration;

	void incrementFrame();
protected:
	void updateAnimation();
public:
	AnimatedObject(sf::Vector2f position, AssetManager& manager);

	void setAnimation(sf::Texture& texture, unsigned frameCount, float duration);
	void setAnimation(Animation& animation);

	sf::Sprite& getSprite() { return sprite; }
	virtual void update() { updateAnimation(); }
	virtual void draw(sf::RenderTarget* target) { target->draw(sprite); }
};