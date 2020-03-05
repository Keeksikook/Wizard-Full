#pragma once
#include"SFML/Graphics.hpp"

struct Animation
{
	float duration = 0;
	sf::Texture texture;
	unsigned frameCount = 0;
};

