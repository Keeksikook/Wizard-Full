#pragma once
#include "Mover.h"
#include "Definitions.h"
class Player :
	public Mover
{
private:
	const float maxSpeed = PlayerSpeed, acceleration = PlayerAccel;
	sf::Vector2f speed = {0, 0};
public:
	Player(sf::Vector2f position, AssetManager& manager, std::string animationName);

	void update(float dt) override;
	std::string getInfo();
	void draw(sf::RenderTarget* target) override;
};

