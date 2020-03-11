#pragma once
#include "Mover.h"
#include <iostream>
#include "Definitions.h"
class Player :
	public Mover
{
private:
	const float maxSpeed = PlayerSpeed, acceleration = PlayerAccel;
	sf::Vector2f speed = {0, 0};
	Animation* animation;
	bool ifSetAnimation(Animation& animation);
	void applyFriction(bool horizontal, float dt);
public:
	Player(sf::Vector2f position, AssetManager& manager, std::string animationName);

	void update(float dt) override;
	virtual void setAnimation(Animation& animation) override;
	void updateAnimationType(sf::Vector2f movement);
	std::string getInfo();
	void draw(sf::RenderTarget* target) override;
};

