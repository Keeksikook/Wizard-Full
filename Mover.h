#pragma once
#include "AnimatedObject.h"
#include "Definitions.h"
class Mover :
	public AnimatedObject
{
private:
protected:
	enum class LookDirection {
		Left, Right
	};

	LookDirection lookDirection = LookDirection::Right;
	void clampToWorld();
	void flipSpriteHorizontal();
public:
	Mover(sf::Vector2f position, AssetManager& manager, std::string animationName);

	virtual bool update(float dt) = 0;
	virtual void draw(sf::RenderTarget* target) = 0;
};

