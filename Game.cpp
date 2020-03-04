#include "Game.h"

//Static functions

//Initializer functions

void Game::initWin()
{
/*
	std::ifstream ifs("Config/window.ini");
	//VS launch dir is different from other
	if (!ifs.is_open())
	{
		std::cout << "Trying secondary directory..\n";
		ifs.open("window.ini");
	}
	if (!ifs.is_open())
	{
		std::cout << "Failed secondary directory..\n";
	}

	

	if (ifs.is_open())
	{
		ifs >> frameRateLimit;
		ifs >> vidMode.width;
		ifs >> vidMode.height;
		ifs >> vSyncOn;
	}
	*/

	std::string title("Wizardry!");
	sf::VideoMode vidMode(960, 540);
	bool vSyncOn = 1;
	short frameRateLimit = 90;

	this->window = new sf::RenderWindow(vidMode, title);
	window->setKeyRepeatEnabled(false);
	window->setFramerateLimit(frameRateLimit);
	window->setVerticalSyncEnabled(vSyncOn);
	//ifs.close();
	
}

//Constructor & Destructor

Game::Game()
{
	loadAssets();
	initWin();
	initStates();

	//Restart clock to fix first deltaTime;
	dtClock.restart();
}

Game::~Game()
{
	delete this->window;
	while (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}

//Functions

void Game::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Game::initStates()
{
	states.push(new MenuState(window, SFEvent, manager));
	states.push(new SplashScreenState(window, SFEvent, manager));
}

void Game::loadAssets()
{
	manager.loadTexture("MainMenuBackground", MainMenuBackground);
	manager.loadFont("Khand", Khand);
	manager.loadAnimation("Torch", Torch, Torch_d, Torch_fc);
	manager.loadAnimation("Test", Test, Test_d, Test_fc);
	manager.loadTexture("SplashScreenImage", SplashScreenImage);
}

void Game::update()
{
	if (!states.empty())
	{
		if (states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
		else
		{
			states.top()->handleEvents();
			states.top()->update(dt);
		}
	}
	else
	{
		this->window->close();
	}
}

void Game::draw()
{
	window->clear();
	if (!states.empty())
		states.top()->draw(window);
	window->display();
}

void Game::run()
{
	while (window->isOpen())
	{
		updateDt();
		update();
		draw();
	}
}