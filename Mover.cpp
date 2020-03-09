#include "Mover.h"

void Mover::flipSpriteHorizontal()
{
	auto scale = getSprite().getScale();

	sf::Vector2f invertedScale = { -1 * scale.x, scale.y };

	getSprite().setScale(invertedScale);
}

Mover::Mover(sf::Vector2f position, AssetManager& manager, std::string animationName)
	:
	AnimatedObject(position, manager, animationName)
{
}

