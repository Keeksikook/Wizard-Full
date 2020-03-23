#include "Enemy.h"

unsigned long Enemy::count = 0;

Enemy::Enemy(sf::Vector2f position, AssetManager& manager, std::string animationName, EnemyArray& enemies)
	:
	Mover(position, manager, animationName),
	enemies(enemies)
{
	count++;
}

Enemy::~Enemy()
{
	count--;
}
