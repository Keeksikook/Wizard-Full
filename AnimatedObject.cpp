#include "AnimatedObject.h"

void AnimatedObject::setRect()
{
	//Variables
	const int frameWidth = sprite.getTexture()->getSize().x / frameCount;
	float frameTime = frameCount / duration;

	float percentage = progress / duration;
	unsigned short index = floorf(percentage * frameCount);


	sprite.setTextureRect(sf::IntRect(index * frameWidth, 0, frameWidth, sprite.getTexture()->getSize().y));
}

void AnimatedObject::updateAnimation(float dt)
{
	//Progress = (progress + dt) % duration
	progress = fmod(progress + dt, duration);
	setRect();	
}

void AnimatedObject::setAnimation(Animation& animation)
{
	sprite.setTexture(animation.texture);
	this->frameCount = animation.frameCount;
	this->duration = animation.duration;

	//Set subrect
	setRect();
}

void AnimatedObject::setAnimation(Animation& animation, float progress)
{
	setAnimation(animation);
	this->progress = progress;
}

void AnimatedObject::centerOrigin()
{
	sf::Vector2f frameSize(sprite.getTextureRect().width / 2.f, sprite.getTextureRect().height / 2.f);

	sprite.setOrigin(frameSize);
}

AnimatedObject::AnimatedObject(sf::Vector2f cornerPosition, AssetManager& manager)
	:
	manager(manager),
	duration(1),
	frameCount(1)
{
	sprite.setPosition(cornerPosition);
}

AnimatedObject::AnimatedObject(sf::Vector2f position, AssetManager& manager, std::string animationName)
	:
	manager(manager)
{
	this->setAnimation(manager.animation(animationName));
	sf::Vector2f origin(this->sprite.getTextureRect().width / 2.f, this->sprite.getTextureRect().height / 2.f);
	this->sprite.setOrigin(origin);
	this->sprite.setPosition(position);
}

AnimatedObject::AnimatedObject(sf::Vector2f position, AssetManager& manager, std::string animationName, float progress)
	:
	AnimatedObject(position, manager, animationName)
{
	this->progress = progress;
}
