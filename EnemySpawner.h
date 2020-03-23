#pragma once
#include "Exploder.h"
#include "Latcher.h"
#include "Definitions.h"
#include <random>
class EnemySpawner
{
private:
	float tickTime = ES_Tick, growth = ES_Growth;
	Player* playerPtr;
	EnemyArray& EA;
	AssetManager& manager;

	void spawn(Enemy* ptr);
public:
	EnemySpawner(Player* playerPtr, EnemyArray& enemyArray, AssetManager& manager);

	void tick(float dt);
};

