#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, AssetManager& manager, std::string animationName)
	:
	Mover(position, manager, animationName)
{

}
