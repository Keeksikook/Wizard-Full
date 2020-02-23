#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow* window, sf::Event& event, AssetManager& manager)
	:
	State(window, event, manager),
	optionSelect({ "New Game", "About", "Exit" }, manager.font("Khand"), {480,260})
{
	backgroundSprite.setTexture(manager.texture("MainMenuBackground"));
	backgroundSprite.setScale(960.f / 1024.f, 540.f / 1024.f);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			optionSelect.next();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			optionSelect.prev();
		}
	}
}

void MenuState::draw(sf::RenderTarget* target)
{
	if (!target)
		target = window;
	target->draw(backgroundSprite);
	optionSelect.draw(target);
}

