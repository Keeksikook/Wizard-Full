#pragma once
#include "SFML/Graphics.hpp"
#include <math.h>

namespace func {
	template<typename T>
	float lenght(const sf::Vector2<T> v) {
		return sqrtf(v.x * v.x + v.y * v.y);
	}

	template<typename T>
	sf::Vector2<T> normalized(const sf::Vector2<T> v) {
		return sf::Vector2<T>(v / lenght(v));
	}

	double randf(float min, float max);

	sf::Vector2f randDir();

}

