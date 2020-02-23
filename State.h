#pragma once
#include "SFML/Graphics.hpp"
#include "AssetManager.h"
#include "Definitions.h"

class State
{
private:

protected:

	sf::RenderWindow* window;
	sf::Event& event;
	bool pausable = true;
	AssetManager& manager;
public:
	enum Situation {
		Running, Paused, Exiting
	};
	Situation setting = Running;

	State(sf::RenderWindow* window, sf::Event& event, AssetManager& manager);
	virtual ~State();

	//Virtuals
	virtual void checkQuit();
	virtual void endState() = 0;
	virtual void update(const float& dt) = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void draw(sf::RenderTarget* target = nullptr) = 0;


	const bool getQuit() const;
	void pause() { if (pausable) setting = Situation::Paused; else perror("This state cannot be paused!\n"); }
	void unPause() { if (pausable) setting = Situation::Running; else perror("This state cannot be paused!\n"); }
	void togglePause() { if (setting == Paused) unPause(); else pause(); }
};
