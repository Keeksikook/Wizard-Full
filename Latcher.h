#pragma once
#include "Enemy.h"
#include "Exploder.h"
class Latcher :
	public Enemy
{
private:

	enum class state {
		Spawning, Moving, Attacking, Dying
	};

	struct Latch {
		Enemy* enemy = nullptr;
		float strenght = 0.f;

		void draw(const Latcher* l, sf::RenderTarget& target) const;
	};

	float attackTimer = LatcherAttackSpeed;
	float spawnTimer = LatcherSpawning_d;
	float deathTimer = LatcherDeath_d;
	float damage = LatcherDamage;
	float range = LatcherRange;
	float movementSpeed = LatcherSpeed;

	state state = state::Spawning;

	void addLatch();
	bool unformedLatches() const;
	void drawLatches(sf::RenderTarget& target) const;

protected:
public:
	std::vector<Latch> latches;

	Latcher(sf::Vector2f position, AssetManager& manager, Player* player, EnemyArray& enemies);

	virtual bool update(float dt) override;
	virtual const bool isAlive() const override;
	virtual void draw(sf::RenderTarget* target);
	virtual const Type getType() const override { return Type::Latcher; }
	void remLatch(Enemy* enemy);
};

