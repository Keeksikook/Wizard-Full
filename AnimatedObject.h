#pragma once
#include"AssetManager.h"

class AnimatedObject
{
private:
	sf::Sprite sprite;
	unsigned frameCount;

	//One cycle duration as seconds
	float duration;

	void setRect();
	void updateAnimation(float dt);
protected:
	AssetManager& manager;
public:
	float progress = 0;
	AnimatedObject(sf::Vector2f cornerPosition, AssetManager& manager);
	AnimatedObject(sf::Vector2f position, AssetManager& manager, std::string animationName);
	AnimatedObject(sf::Vector2f position, AssetManager& manager, std::string animationName, float progress);

	virtual void setAnimation(Animation& animation);
	virtual void setAnimation(Animation& animation, float progress);

	sf::Sprite& getSprite() { return sprite; }
	const sf::Sprite& getConstSprite() const { return sprite; }
	void centerOrigin();

	//Update the object(to be overloaded)
	virtual bool update(float dt) { updateAnimation(dt); return false; }


	virtual void draw(sf::RenderTarget* target) { target->draw(sprite); }
};