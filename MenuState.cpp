#include "MenuState.h"



MenuState::MenuState(sf::RenderWindow* window, AssetManager& manager)
	:
	State(window, manager),
	optionSelect({ "New Game", "About", "Exit" }, manager.font(Khand), {0.5, 0.5}, this, *window),
	torch({40, 100}, manager, Torch),
	test({ 100 , 100 }, manager, Test)
	
{
	pausable = false;

	backgroundSprite.setTexture(manager.texture(MainMenuBackground));

	if (D_COUT)
	{
		
	}
}

MenuState::~MenuState()
{
	endState();
}

void MenuState::endState()
{
	setting = MenuState::Exiting;
}

void MenuState::updateInput(const float& dt)
{
	checkQuit();
}

void MenuState::update(const float& dt)
{
	optionSelect.reSize();
	if (setting == Running)
	{
		updateInput(dt);
		torch.update(dt);
		test.update(dt);
	}
}

void MenuState::draw(sf::RenderTarget* target)
{
	if (!target)
		target = window;

	window->setView(window->getDefaultView());

	target->draw(backgroundSprite);
	optionSelect.draw(target);
	torch.draw(target);
	test.draw(target);
}

int MenuState::handleEvent(sf::Event& event)
{
	unsigned selectionNr = -1;
	/*
	-1 => No selection 
	0  => New Game
	1  => About
	2  => Exit
	*/

	switch (event.type)
	{
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::Resized:
		optionSelect.reSize();
		break;
	case sf::Event::MouseMoved:
		optionSelect.update(*window);
		break;
	case sf::Event::MouseButtonPressed:
		{
			int selection = optionSelect.ifSelect();
			if (selection == 2)
			{
				endState();
			}
			else if (selection == 1)
			{
				//About
				selectionNr = 1;
			}
			else if (selection == 0)
			{
				selectionNr = 0;
			}
			else
			{
				perror("menustate.cpp-ln95:selection was unexpected\n");
			}
		}
		break;
	case sf::Event::KeyPressed:
		{
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
				int selection = optionSelect.select();
				if (selection == 2)
				{
					endState();
				}
				else if (selection == 1)
				{
					//About
					selectionNr = 1;
				}
				else if (selection == 0)
				{
					selectionNr = 0;
				}
				else
				{
					perror("menustate.cpp-ln103:selection was unexpected\n");
				}
				
			}
			else if (event.key.code == sf::Keyboard::BackSpace)
			{
				endState();
			}
			else if (event.key.code == sf::Keyboard::W)
			{
				optionSelect.prev();
			}
			else if (event.key.code == sf::Keyboard::S)
			{
				optionSelect.next();
			}
			else if (event.key.code == sf::Keyboard::A)
			{
				optionSelect.prev();
			}
			else if (event.key.code == sf::Keyboard::D)
			{
				optionSelect.next();
			}
			else if (event.key.code == sf::Keyboard::Up)
			{
				optionSelect.prev();
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				optionSelect.next();
			}
			else if (event.key.code == sf::Keyboard::Left)
			{
				optionSelect.prev();
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				optionSelect.next();
			}
			break;
	}
	}
	return selectionNr;
}

void MenuState::resize()
{
	auto view = window->getDefaultView().getSize();
	backgroundSprite.setScale(view.x / 1024.f, view.y / 1024.f);
}

