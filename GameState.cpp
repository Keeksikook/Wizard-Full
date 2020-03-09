#include "GameState.h"


GameState::GameState(sf::RenderWindow* window, AssetManager& manager, sf::View& playerView)
	:
	State(window, manager),
	wizard({ WorldSizeX * 0.5f, WorldSizeY * 0.5f }, manager, "WizardIdle"),
	playerView(playerView)
{
	background.setTexture(manager.texture("Grass"));
	sf::Vector2f backgroundScale(float(WorldSizeX) / 960.f, float(WorldSizeY) / 540.f);
	background.setScale(backgroundScale);;
	background.setPosition(0, 0);

	pausable = true;
}


void GameState::endState()
{
	window->setView(window->getDefaultView());
	setting = Exiting;
}

void GameState::update(const float& dt)
{
	if (setting == Running)
	{
		updateInput(dt);
		wizard.update(dt);
	}
}

void GameState::updateInput(const float& dt)
{
	checkQuit();
}

void GameState::draw(sf::RenderTarget* target)
{
	if (D_COUT)
	{
		std::cout << "Origin: " << wizard.getSprite().getOrigin().x << " : " << wizard.getSprite().getOrigin().y << "\n";
		std::cout << "pos: " << wizard.getSprite().getPosition().x << " : " << wizard.getSprite().getPosition().y << "\n";
	}

	target->setView(playerView);
	target->draw(background);
	wizard.draw(target);
}

int GameState::handleEvent(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::Resized:
		//Fix view 
	{ //This block is needed to avoid C2360
		auto view = window->getView();
		view.setSize(event.size.width, event.size.height);
	}
	break;
	case sf::Event::MouseMoved:
		break;
	case sf::Event::MouseButtonPressed:
		break;
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::P)
		{
			togglePause();
		}
		if (event.key.code == sf::Keyboard::Pause)
		{
			togglePause();
		}
		if (event.key.code == sf::Keyboard::Enter)
		{
			std::cout << wizard.getInfo();
		}
		else if (event.key.code == sf::Keyboard::BackSpace)
		{
			endState();
		}
		else if (event.key.code == sf::Keyboard::W)
		{
		}
		else if (event.key.code == sf::Keyboard::S)
		{
		}
		else if (event.key.code == sf::Keyboard::A)
		{
		}
		else if (event.key.code == sf::Keyboard::D)
		{
		}
		else if (event.key.code == sf::Keyboard::Up)
		{
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
		}
		else if (event.key.code == sf::Keyboard::Left)
		{
		}
		else if (event.key.code == sf::Keyboard::Right)
		{
		}
		break;
	}
	return -1;
}
