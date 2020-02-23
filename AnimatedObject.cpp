#include "AnimatedObject.h"

void AnimatedObject::incrementFrame()
{
	//Variables
	const sf::Texture& texture = *sprite.getTexture();
	const int frameWidth = texture.getSize().x / frameCount;
	int currentIndex = sprite.getTextureRect().left / frameWidth;
	int maxIndex = sprite.getTexture()->getSize().x / frameWidth;
	//>>
	if(currentIndex < maxIndex - 1)
		sprite.setTextureRect(sf::IntRect((currentIndex + 1) * frameWidth, 0, frameWidth, sprite.getTextureRect().height));
	else
		sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, sprite.getTextureRect().height));
}

void AnimatedObject::updateAnimation()
{
	if (c_fromLastSwitch.getElapsedTime().asSeconds() >= duration/float(frameCount)) {
		c_fromLastSwitch.restart();
		incrementFrame();
	}
}

void AnimatedObject::setAnimation(sf::Texture& texture, unsigned frameCount, float duration)
{
	sprite.setTexture(texture);
	this->frameCount = frameCount;
	this->duration = duration;

	//Set subrect
	sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x / frameCount, texture.getSize().y));
	//Reset clock
	c_fromLastSwitch.restart();
}

void AnimatedObject::setAnimation(Animation& animation)
{
	sprite.setTexture(animation.texture);
	this->frameCount = animation.frameCount;
	this->duration = animation.duration;

	//Set subrect
	sprite.setTextureRect(sf::IntRect(0, 0, animation.texture.getSize().x / frameCount, animation.texture.getSize().y));
	//Reset clock
	c_fromLastSwitch.restart();
}

AnimatedObject::AnimatedObject(sf::Vector2f position, AssetManager& manager)
	:
	manager(manager),
	duration(1),
	frameCount(1)
{
	sprite.setPosition(position);
}
