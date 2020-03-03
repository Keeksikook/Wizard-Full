#pragma once
#include "State.h"
//#include "AnimatedObject.h" kui soovib animeerida splash screeni
class SplashScreenState :
	public State
{
private:
	sf::Time wholeDuration, fadeIn, currentDuration;
	sf::Sprite image;
protected:


public:
	SplashScreenState(sf::RenderWindow* window, sf::Event& event, AssetManager& manager);
	virtual ~SplashScreenState();

	//Overrides
	void checkQuit() override;
	void endState() override;
	void update(const float& dt) override;
	void updateInput(const float& dt) override;
	void draw(sf::RenderTarget* target = nullptr) override;
	void handleEvents() override;

};

