#pragma once
#include "SFML/Graphics.hpp"

namespace func {
	template<typename T>
	float lenght(const sf::Vector2<T> v) {
		return sqrtf(v.x * v.x + v.y * v.y);
	}

	template<typename T>
	sf::Vector2<T> normalized(const sf::Vector2<T> v) {
		return sf::Vector2<T>(v / lenght(v));
	}
}

