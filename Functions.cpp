#include "Functions.h"
#include <random>

namespace func {
	double randomIncl(double minimum, double maximum) {
		float delta = maximum - minimum;
		return fmod(rand(), delta + 1.f) - delta / 2.f;
	}
	double randf(float min, float max)
	{
		return min + static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / (max - min)));
	}
	sf::Vector2f randDir()
	{
		float angle = randf(0, 1) * 2 * M_PI;
		return sf::Vector2f(cos(angle), sin(angle));
	}
}