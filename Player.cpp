#include "Player.h"

Player::Player(sf::Vector2f position, AssetManager& manager, std::string animationName)
	:
	Mover(position, manager, animationName)
{
}

void Player::update(float dt)
{
	LookDirection oldDir = lookDirection;
	sf::Vector2f oldPos = getSprite().getPosition();


	//find if moving
	bool moving = false;
	if (
		(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ||
		(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		)
	{
		moving = true;
	}
		

	//Decelerate the player if not trying to move
	if(!moving)
	{
		sf::Vector2f negativeSpeed(-speed.x, -speed.y);
		speed += negativeSpeed * dt * PlayerDecel;
	}

	//If player speed is low, set to 0
	float speed_lenght = sqrtf(speed.x * speed.x + speed.y * speed.y);
	if (speed_lenght < 0.01f)
		speed = { 0, 0 };
	

	//Accelerate if key is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if(speed.x > 0 && AntiSlip)
			speed.x *= dt;
		speed += sf::Vector2f(-PlayerAccel * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (speed.x < 0 && AntiSlip)
			speed.x *= dt;
		speed += sf::Vector2f(PlayerAccel * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (speed.y > 0 && AntiSlip)
			speed.y *= dt;
		speed += sf::Vector2f(0, -PlayerAccel * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (speed.y < 0 && AntiSlip)
			speed.y *= dt;
		speed += sf::Vector2f(0, PlayerAccel * dt);
	}

	//Clamp speed
	speed_lenght = sqrtf(speed.x * speed.x + speed.y * speed.y);
	if (speed_lenght > maxSpeed)
	{
		sf::Vector2f speed_normal = speed / speed_lenght;
		speed = maxSpeed * speed_normal;
	}

	getSprite().move(speed);
	if ((getSprite().getPosition() - oldPos).x > 0)
		lookDirection = LookDirection::Right;
	else if ((getSprite().getPosition() - oldPos).x == 0)
	{
	}
	else
		lookDirection = LookDirection::Left;

	//Flip sprite if needed
	if (lookDirection != oldDir)
		flipSpriteHorizontal();	

	updateAnimation();
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
