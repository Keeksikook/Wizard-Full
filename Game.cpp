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

	bool vSyncOn = 1;
	short frameRateLimit = 90;
	sf::VideoMode vMode(WindowWidth, WindowHeight);

	this->window = new sf::RenderWindow(vMode, Title, sf::Style::None);
	window->setVerticalSyncEnabled(true);
	//ifs.close();
	
}

//Constructor & Destructor

Game::Game()
{
	loadAssets();
	initWin();
	initStates();

	playerView.setSize(WorldSizeX, WorldSizeY);
	playerView.setCenter(WorldSizeX / 2.f, WorldSizeY / 2.f);

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

void Game::pollEvent()
{
	int selection = -1;
	State* gameState = nullptr;
	while (window->pollEvent(SFEvent))
	{
		if (states.size() > 0)
		{
			selection = states.top()->handleEvent(SFEvent);

			//User selected 'New Game'
			if (selection == 0)
				gameState = new GameState(window, manager, playerView);

			//User selected 'About'
			else if (selection == 1)
			{

			}

			//User selected 'Exit'
			else if (selection == 2)
			{
				states.top()->endState();

				//Break to outside of while
				break;
			}
		}
	}
	if (gameState != nullptr)
	{
		states.push(gameState);
		if(D_COUT)
			std::cout << "Pushed new game!\n";
	}
}

void Game::initStates()
{
	states.push(new MenuState(window, manager));
	states.push(new SplashScreenState(window, manager, (MenuState*)states.top()));
}

void Game::loadAssets()
{
	manager.loadTexture("MainMenuBackground", MainMenuBackground);
	manager.loadFont("Khand", Khand);
	manager.loadAnimation("Torch", Torch, Torch_d, Torch_fc);
	manager.loadAnimation("Test", Test, Test_d, Test_fc);
	manager.loadAnimation("WizardIdle", WizardIdle, WizardIdle_d, WizardIdle_fc);
	manager.loadTexture("SplashScreenImage", SplashScreenImage);
	manager.loadTexture("Grass", Grass);
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
		pollEvent();
		update();
		draw();
	}
}