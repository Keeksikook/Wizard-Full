#pragma once
#include"SFML/Graphics.hpp"
#include"AssetManager.h"

class AnimatedObject
{
private:
	sf::Sprite sprite;
	unsigned frameCount;

	//One cycle duration as seconds
	float duration;

	void setRect();
protected:
	AssetManager& manager;
	void updateAnimation(float dt);
public:
	float progress = 0;
	AnimatedObject(sf::Vector2f cornerPosition, AssetManager& manager);
	AnimatedObject(sf::Vector2f position, AssetManager& manager, std::string animationName);
	AnimatedObject(sf::Vector2f position, AssetManager& manager, std::string animationName, float progress);

	virtual void setAnimation(Animation& animation);
	virtual void setAnimation(Animation& animation, float progress);

	sf::Sprite& getSprite() { return sprite; }
	void centerOrigin();

	//Update the object(to be overloaded)
	virtual void update(float dt) { updateAnimation(dt); }


	virtual void draw(sf::RenderTarget* target) { target->draw(sprite); }
};