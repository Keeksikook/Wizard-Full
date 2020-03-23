#pragma once
#include "Mover.h"
#include "Functions.h"
#include "Player.h"
class Enemy;

typedef std::vector<std::unique_ptr<Enemy>> EnemyArray;

class Enemy :
	public Mover
{


private:
protected:
	Player* playerPtr = nullptr;
	EnemyArray& enemies;
	static unsigned long count;
public:
	enum class Type {
		Base, Exploder, Latcher
	};


	Enemy(sf::Vector2f position, AssetManager& manager, std::string animationName, EnemyArray& enemies);
	~Enemy();
	virtual const bool isAlive() const = 0;
	virtual bool update(float dt) = 0;
	virtual void draw(sf::RenderTarget* target) = 0;
	virtual const Type getType() const { return Type::Base; }
};


