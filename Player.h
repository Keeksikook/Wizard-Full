#pragma once
#include "Mover.h"
#include <iostream>
class Player :
	public Mover
{
private:
	const float maxSpeed = PlayerSpeed, acceleration = PlayerAccel;
	sf::Vector2f speed = {0, 0};
	Animation* animation;
	bool ifSetAnimation(Animation& animation);
	void applyFriction(bool horizontal, float dt);
	float hp = PlayerHP;

public:
	Player(sf::Vector2f position, AssetManager& manager, std::string animationName);

	bool update(float dt) override;
	virtual void setAnimation(Animation& animation) override;
	void updateAnimationType(sf::Vector2f movement);
	void printInfo();
	void draw(sf::RenderTarget* target) override;
	void hurt(float damage) { hp -= damage; }

};

