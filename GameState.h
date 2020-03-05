#pragma once
#include "State.h"
#include "AnimatedObject.h"
class GameState :
	public State
{
private:
	AnimatedObject wizard;
	sf::Sprite background;
public:
	GameState(sf::RenderWindow* window, AssetManager& manager);

	//Virtuals
	virtual void endState();
	virtual void update(const float& dt);
	virtual void updateInput(const float& dt);
	virtual void draw(sf::RenderTarget* target = nullptr);
	virtual int handleEvent(sf::Event& event);
	std::string getType() override { return "GameState"; }

};

