#include "Player.h"

Player::Player(sf::Vector2f position, AssetManager& manager, std::string animationName)
	:
	Mover(position, manager, animationName)
{
}

void Player::update(float dt)
{
	sf::Vector2f oldPos = getSprite().getPosition();

	//Accelerate if key is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		applyFriction(false, dt);
		speed += sf::Vector2f(-PlayerAccel * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		applyFriction(false, dt);
		speed += sf::Vector2f(PlayerAccel * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		applyFriction(true, dt);
		speed += sf::Vector2f(0, -PlayerAccel * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		applyFriction(true, dt);
		speed += sf::Vector2f(0, PlayerAccel * dt);
	}

	//Decelerate the player if not trying to move
	applyFriction(true, dt);
	applyFriction(false, dt);

	//If player speed is low, set to 0
	float speed_lenght = sqrtf(speed.x * speed.x + speed.y * speed.y);
	if (speed_lenght < 0.01f)
		speed = { 0, 0 };

	//Clamp speed
	speed_lenght = sqrtf(speed.x * speed.x + speed.y * speed.y);
	if (speed_lenght > maxSpeed)
	{
		sf::Vector2f speed_normal = speed / speed_lenght;
		speed = maxSpeed * speed_normal;
	}

	getSprite().move(speed);
	sf::Vector2f movement = getSprite().getPosition() - oldPos;

	//if (movement.x > 0)
	//	lookDirection = LookDirection::Right;
	//else if (movement.x == 0)
	//{
	//}
	//else
	//	lookDirection = LookDirection::Left;

	updateAnimationType(movement);
	updateAnimation(dt);
}

void Player::setAnimation(Animation& animation)
{
	this->animation = &animation;
	AnimatedObject::setAnimation(animation);
}

//if needed, set animation; return true if needed
bool Player::ifSetAnimation(Animation& animation)
{
	if (this->animation == &animation)
		return false;
	setAnimation(animation);
	return true;
}

void Player::applyFriction(bool horizontal, float dt)
{
	if (horizontal)
	{
		sf::Vector2f horizontalSpeed = { speed.x, 0 };
		speed -= horizontalSpeed * dt * PlayerDecel;
	}
	else
	{
		sf::Vector2f verticalSpeed = { 0, speed.y };
		speed -= verticalSpeed * dt * PlayerDecel;
	}
}

void Player::updateAnimationType(sf::Vector2f movement)
{
	if (movement.x > 0)
		ifSetAnimation(manager.animation("WizardRight"));
	else if (movement.x < 0)
		ifSetAnimation(manager.animation("WizardLeft"));
	else
	{
		ifSetAnimation(manager.animation("WizardIdle"));
	}
}


std::string Player::getInfo()
{
	auto speed_lenght = sqrtf(speed.x * speed.x + speed.y * speed.y);
	return (std::string)"Pos:[" + std::to_string(getSprite().getPosition().x) + " : " + std::to_string(getSprite().getPosition().y) + "]\nSpd:[" +
		std::to_string(speed.x) + " : " + std::to_string(speed.y) + "]\nSpd = " + 
		std::to_string(speed_lenght) + "\n";
}

void Player::draw(sf::RenderTarget* target)
{
	target->draw(getSprite());
}
