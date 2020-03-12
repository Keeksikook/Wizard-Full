#pragma once
#include "Mover.h"
class Enemy :
	public Mover
{
private:
protected:
public:
	Enemy(sf::Vector2f position, AssetManager& manager, std::string animationName);
};

