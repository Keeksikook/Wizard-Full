#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, AssetManager& manager)
	:
	State(window, manager),
	wizard(window->getView().getCenter(), manager)
{
	wizard.setAnimation(manager.animation("WizardIdle"));
	wizard.getSprite().setScale(4, 4);
	background.setTexture(manager.texture("Grass"));
	pausable = true;
}


void GameState::endState()
{
	setting = Exiting;
}

void GameState::update(const float& dt)
{
	if (setting == Running)
	{
		updateInput(dt);
		wizard.update();
	}
}

void GameState::updateInput(const float& dt)
{
	checkQuit();
}

void GameState::draw(sf::RenderTarget* target)
{
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
		sf::FloatRect view(0, 0, event.size.width, event.size.height);
		window->setView(sf::View(view));
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
