#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, AssetManager& manager, std::string animationName, EnemyArray& enemies)
	:
	Mover(position, manager, animationName),
	enemies(enemies)
{

}

Enemy::~Enemy()
{
	std::cout << "Erased enemy!\n";
}
