#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow* window, sf::Event& event, AssetManager& manager)
	:
	State(window, event, manager),
	optionSelect({ "New Game", "About", "Exit" }, manager.font("Khand"), {480,260}, this),
	torch({200, 200}, manager),
	test({400, 200}, manager)
	
{
	backgroundSprite.setTexture(manager.texture("MainMenuBackground"));
	backgroundSprite.setScale(960.f / 1024.f, 540.f / 1024.f);
	torch.setAnimation(manager.animation("Torch"));
	test.setAnimation(manager.animation("Test"));
}

MenuState::~MenuState()
{
	endState();
}

void MenuState::endState()
{
}

void MenuState::updateInput(const float& dt)
{
	checkQuit();
}

void MenuState::update(const float& dt)
{
	if (setting == Running)
	{
		updateInput(dt);
		torch.update();
		test.update();
	}
}

void MenuState::draw(sf::RenderTarget* target)
{
	if (!target)
		target = window;
	target->draw(backgroundSprite);
	optionSelect.draw(target);
	torch.draw(target);
	test.draw(target);
}

void MenuState::handleEvents()
{
	while (window->pollEvent(event))
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
			optionSelect.update(*window);
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
				optionSelect.select();
			}
			else if (event.key.code == sf::Keyboard::BackSpace)
			{
				setting = State::Exiting;
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
}

