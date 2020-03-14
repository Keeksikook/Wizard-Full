#include "Exploder.h"

const float Exploder::damageDealt(float distance) const
{
	//https://gyazo.com/6bc17748f664384b6bc7968fa9388f6d

	if (distance < 2.602f)
		return 200.f;
	else if (distance > 210.9f)
		return 0.f;
	else
		return 9406.4f / (distance + 36.9f) - 38.f;
}

Exploder::Exploder(sf::Vector2f position, AssetManager& manager, Player* player, EnemyArray& enemies)
	:
	Enemy(position, manager, ExploderIdle, enemies)
{
	this->playerPtr = player;
}

bool Exploder::update(float dt)
{
	
	sf::Vector2f position = getSprite().getPosition();
	sf::Vector2f exploderToPlayer = playerPtr->getSprite().getPosition() - position;
	sf::Vector2f normal = func::normalized(exploderToPlayer);

	if (hp <= 0 && state != state::Charging)
	{
		state = state::Dying;
		setAnimation(manager.animation(ExploderDeath));
	}

	if (state == state::Moving)
	{
		if (func::lenght(exploderToPlayer) > ExploderRange)
		{
			LookDirection oldDir = lookDirection;
			if (normal.x > 0)
				lookDirection = LookDirection::Right;
			else if (normal.x < 0)
				lookDirection = LookDirection::Left;

			getSprite().move(normal * ExploderSpeed * dt);

			//Make sure he's not outside of world
			clampToWorld();

			if (oldDir != lookDirection)
				flipSpriteHorizontal();
		}
		else
		{
			state = state::Charging;
			setAnimation(manager.animation(ExploderCharging));
		}
	}
	else if (state == state::Charging)
	{
		chargingTimer -= dt;
		if (chargingTimer <= 0)
		{
			float damageToDeal = damageDealt(func::lenght(exploderToPlayer));
			playerPtr->hurt(damageToDeal);
			state = state::Exploding;
			setAnimation(manager.animation(ExploderExplosion));
		}
	}
	else if (state == state::Exploding)
	{
		explosionTimer -= dt;
		if (explosionTimer <= 0)
			return false; //return false, so the vector will delete this object
	}
	else if (state == state::Dying)
	{
		deathTimer -= dt;
		if (deathTimer <= 0)
			return false; //return false, so the vector will delete this object
	}


	//update animation
	AnimatedObject::update(dt);
	return true;
}

const bool Exploder::alive() const
{
	return (state != state::Dying && state != state::Exploding);
}

void Exploder::draw(sf::RenderTarget* target)
{
	AnimatedObject::draw(target);
}

void Exploder::coutInfo() const 
{
	std::cout << "Charge: " << chargingTimer << "\n";
	std::cout << "Expl: " << explosionTimer << "\n";
	std::cout << "death: " << deathTimer << "\n";
}
