#pragma once
#include<stack>
#include<stdio.h>
#include<iostream>
#include"MenuState.h"
#include"SplashScreenState.h"

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

	//Initialization

	void initWin();
	void initStates();
	void loadAssets();

	//Functions
	void updateDt();


public:

	//Constructor & Destructor

	Game();
	virtual ~Game();

	//Functions

	void update();
	void draw();
	void run();
};

