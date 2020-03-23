#include "EnemySpawner.h"
#include "EnemySpawner.h"

void EnemySpawner::spawn(Enemy* ptr)
{
	EA.emplace_back(ptr);
}

EnemySpawner::EnemySpawner(Player* playerPtr, EnemyArray& enemyArray, AssetManager& manager)
	:
	playerPtr(playerPtr),
	EA(enemyArray),
	manager(manager)
{
	srand(time(NULL));
}

void EnemySpawner::tick(float dt)
{
	growth += ES_Accel * dt;
	tickTime -= growth * dt;
	if (tickTime <= 0)
	{
		tickTime = ES_Tick + tickTime;
		unsigned int random = rand();
		unsigned short choice = random % 3;
		if (choice == 0)
		{
			//Wait
		}
		else if (choice == 1)
		{
			sf::Vector2f pos(playerPtr->getSprite().getPosition() + func::randDir() * 50.f);
			//Spawn one
			if (random % EnemyCount == 0) {
				spawn(new Exploder(pos, manager, playerPtr, EA));
			}
		}
		else if (choice == 2)
		{
			//Spawn a few
		}
	}
}
