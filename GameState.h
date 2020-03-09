#pragma once
#include "State.h"
#include "Player.h"
class GameState :
	public State
{
private:
	Player wizard;
	sf::Sprite background;
	sf::View& playerView;
public:
	GameState(sf::RenderWindow* window, AssetManager& manager, sf::View& playerView);

	//Virtuals
	virtual void endState();
	virtual void update(const float& dt);
	virtual void updateInput(const float& dt);
	virtual void draw(sf::RenderTarget* target = nullptr);
	virtual int handleEvent(sf::Event& event);
	std::string getType() override { return "GameState"; }

};

