#pragma once
#include "Mover.h"
#include "Definitions.h"
class Player :
	public Mover
{
private:
	const float maxSpeed = PlayerSpeed, acceleration = PlayerAccel;
	sf::Vector2f speed = {0, 0};
	Animation* animation;
public:
	Player(sf::Vector2f position, AssetManager& manager, std::string animationName);

	void update(float dt) override;
	virtual void setAnimation(Animation& animation) override;
	void updateAnimation(sf::Vector2f movement);
	std::string getInfo();
	void draw(sf::RenderTarget* target) override;
};

