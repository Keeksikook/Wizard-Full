#pragma once
#include "MenuState.h"
#include <iostream>
#include <wtypes.h>

class SplashScreenState :
	public State
{
private:
	sf::Time wholeDuration, fadeIn, currentDuration;
	sf::Sprite image;

	MenuState* menuState;
protected:


public:
	SplashScreenState(sf::RenderWindow* window, AssetManager& manager, MenuState* menuState);
	virtual ~SplashScreenState();

	//Overrides
	void checkQuit() override;
	void endState() override;
	void update(const float& dt) override;
	void updateInput(const float& dt) override;
	void draw(sf::RenderTarget* target = nullptr) override;
	int handleEvent(sf::Event& event) override;
	std::string getType() override { return "SplashScreenState"; }

};

