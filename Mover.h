#pragma once
#include "AnimatedObject.h"
class Mover :
	public AnimatedObject
{
private:
protected:
	enum class LookDirection {
		Left, Right
	};

	LookDirection lookDirection = LookDirection::Right;

	void flipSpriteHorizontal();
public:
	Mover(sf::Vector2f position, AssetManager& manager, std::string animationName);

	virtual void update(float dt) = 0;
	virtual void draw(sf::RenderTarget* target) = 0;
};

