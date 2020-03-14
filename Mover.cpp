#include "Mover.h"

void Mover::clampToWorld()
{
	//https://gyazo.com/f1b5d92f7364596baa5ec6598bb1ff00

	sf::Vector2f position = getSprite().getPosition();
	float width = getSprite().getGlobalBounds().width;
	float height = getSprite().getGlobalBounds().height;

	//Player left of world
	if (position.x - width / 2 < 0)
		getSprite().move(-(position.x - width / 2), 0);

	//Player right of world
	if (position.x + width / 2 > WorldSizeX)
		getSprite().move(WorldSizeX - (position.x + width / 2), 0);

	//Player above world
	if (position.y - height / 2 < 0)
		getSprite().move(0, -(position.y - height / 2));

	//Player below world
	if (position.y + height / 2 > WorldSizeY)
		getSprite().move(0, WorldSizeY - (position.y + height / 2));
}

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

