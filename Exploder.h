#pragma once
#include "Enemy.h"
class Exploder :
	public Enemy
{
private:
	float hp = ExploderDMG;
	float damage = ExploderHP;
	float range = ExploderRange;

	float chargingTimer = ExploderChargeTime;
	float explosionTimer = Explosion_d;
	float deathTimer = ExploderDeath_d;

	const float damageDealt(float distance) const;

	enum class state {
		Moving, Charging, Exploding
	};

	state state = state::Moving;
protected:
public:
	Exploder(sf::Vector2f position, AssetManager& manager, Player* player, EnemyArray& enemies);

	virtual bool update(float dt) override;
	virtual const bool isAlive() const;
	virtual void draw(sf::RenderTarget* target);
	virtual const Type getType() const override { return Type::Exploder; }
};

