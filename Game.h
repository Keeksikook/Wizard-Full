#pragma once
#include<stack>
#include"SplashScreenState.h"
#include"GameState.h"

class Game
{
private:

	//Variables

	sf::RenderWindow* window;
	sf::Event SFEvent;
	sf::Clock dtClock;
	float dt = 0;
	std::stack<State*> states;
	AssetManager manager;
	sf::View playerView;


	//Initialization

	void initWin();
	void initStates();
	void loadAssets();

	//Functions
	void updateDt();
	void pollEvent();


public:

	//Constructor & Destructor

	Game();
	virtual ~Game();

	//Functions

	void update();
	void draw();
	void run();
};

