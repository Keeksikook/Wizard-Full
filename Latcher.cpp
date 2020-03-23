#include "Latcher.h"

void Latcher::addLatch()
{
	for (auto& e : enemies)
	{
		bool enemyUsed = false;
		for (Latch& l : latches)
		{
			if (l.enemy == e.get())
			{
				enemyUsed = true;
				break;
			}
		}
		if (!enemyUsed)
		{
			latches.push_back(Latch{ e.get(), 0.f });
			break;
		}
	}
}

bool Latcher::unformedLatches() const
{
	for (const Latch& l : latches)
	{
		if (l.strenght < 1.f)
			return true;
	}
	return false;
}

void Latcher::drawLatches(sf::RenderTarget& target) const
{
	for (auto& latch : latches)
		latch.draw(this, target);
}

Latcher::Latcher(sf::Vector2f position, AssetManager& manager, Player* player, EnemyArray& enemies)
	:
	Enemy(position, manager, LatcherSpawning, enemies)
{
	this->playerPtr = player;
	

	//Pick random enemy(not latcher)
	std::vector<Enemy*> population;

	for (auto& enemy : enemies)
		if (enemy.get()->getType() != Type::Latcher)
			population.emplace_back(enemy.get());

	Enemy* selectedEnemy = nullptr;
	selectedEnemy = population[int(func::randf(0, population.size() - 1))];

	latches.push_back(Latch{ selectedEnemy, 1.f });
}

bool Latcher::update(float dt)
{
	sf::Vector2f position = getSprite().getPosition();
	sf::Vector2f latcherToPlayer = playerPtr->getSprite().getPosition() - position;
	sf::Vector2f normal = func::normalized(latcherToPlayer);

	if (latches.size() < 1 && state != state::Dying)
	{
		state = state::Dying;
		setAnimation(manager.animation(LatcherDeath));
	}

	if (state == state::Spawning)
	{
		spawnTimer -= dt;
		if (spawnTimer <= 0)
		{
			state = state::Moving;
			setAnimation(manager.animation(LatcherMoving));
		}
	}
	else if (state == state::Moving)
	{
		if (func::lenght(latcherToPlayer) > range)
		{
			LookDirection oldDir = lookDirection;
			if (normal.x > 0)
				lookDirection = LookDirection::Right;
			else if (normal.x < 0)
				lookDirection = LookDirection::Left;

			getSprite().move(normal * this->movementSpeed * dt);

			//Make sure he's not outside of world
			clampToWorld();
		}
		else
		{
			state = state::Attacking;
			setAnimation(manager.animation(LatcherAttacking));
		}
	}
	else if (state == state::Attacking)
	{
		if (func::lenght(latcherToPlayer) < range)
		{
			this->attackTimer -= dt;
			if (attackTimer <= 0)
			{
				//Add projectile
				attackTimer = LatcherAttackSpeed;
			}
		}
		else
		{
			state = state::Moving;
			setAnimation(manager.animation(LatcherMoving));
		}
	}
	else if (state == state::Dying)
	{
		deathTimer -= dt;
		if (deathTimer <= 0)
			return false; //return false, so the vector will delete this object
	}

	//if (!unformedLatches())
	//	addLatch();

	//update animation
	AnimatedObject::update(dt);
	return true;
}

const bool Latcher::isAlive() const
{
	return (deathTimer > 0);
}

void Latcher::draw(sf::RenderTarget* target)
{
	target->draw(getSprite());
	drawLatches(*target);
}

//Removes all latches to the specific enemy
void Latcher::remLatch(Enemy* enemy)
{
	for (auto it = latches.begin(); it != latches.end();)
	{
		if (it->enemy == enemy)
		{
			it = latches.erase(it);
		}
		else
			it++;
	}
}

void Latcher::Latch::draw(const Latcher* l, sf::RenderTarget& target) const
{
	sf::Vertex line[] =
	{
		sf::Vertex(l->getConstSprite().getPosition()),
		sf::Vertex(this->enemy->getConstSprite().getPosition())
	};
	line->color = sf::Color(255, 255, 255, 255 * this->strenght);
	target.draw(line, 2, sf::Lines);
}
