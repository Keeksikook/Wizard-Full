#include "OptionSelect.h"

void OptionSelect::styleBefore()
{
	cursorPtr->setFillColor(notSelected.getFillColor());
	cursorPtr->setOutlineColor(notSelected.getOutlineColor());
	cursorPtr->setStyle(notSelected.getStyle());
	cursorPtr->setOutlineThickness(notSelected.getOutlineThickness());
}

void OptionSelect::styleAfter()
{
	cursorPtr->setFillColor(selected.getFillColor());
	cursorPtr->setOutlineColor(selected.getOutlineColor());
	cursorPtr->setStyle(selected.getStyle());
	cursorPtr->setOutlineThickness(selected.getOutlineThickness());
}

void OptionSelect::increment()
{
	if (cursorPtr != &options.back()) {
		cursorPtr++;
	}
	else {
		cursorPtr = &options.front();
	}
}

void OptionSelect::decrement()
{
	if (cursorPtr != &options.front()) {
		cursorPtr--;
	}
	else {
		cursorPtr = &options.back();
	}
}

OptionSelect::OptionSelect(std::vector<std::string> options, sf::Font& font, sf::Vector2f position, sf::RenderWindow& window)
	:
	position(position),
	window(window)
{
	//Non-Selected style
	notSelected.setFont(font);
	notSelected.setFillColor(sf::Color::White);
	notSelected.setOutlineColor(sf::Color::Black);
	notSelected.setStyle(sf::Text::Italic);
	notSelected.setOutlineThickness(1.f);
	notSelected.setString("#NOTSELECTED#");
	////

	//Selected style
	selected.setFont(font);
	selected.setFillColor(sf::Color::Yellow);
	selected.setOutlineColor(sf::Color::Black);
	selected.setStyle(sf::Text::Italic | sf::Text::Bold);
	selected.setOutlineThickness(1.f);
	selected.setString("#SELECTED#");
	////

	//Format & position every option
	for (auto& txt : options) {
		this->options.push_back(notSelected);
		this->options.back().setFont(font);
		this->options.back().setString(txt);
	}
	////

	//Format the first option to be selected
	this->options[0].setFillColor(selected.getFillColor());
	this->options[0].setOutlineColor(selected.getOutlineColor());
	this->options[0].setStyle(selected.getStyle());
	this->options[0].setOutlineThickness(selected.getOutlineThickness());
	////

	//Select the first option
	cursorPtr = &this->options[0];

	//Set the positions using resize()
	reSize();
}

void OptionSelect::reSize()
{
	float actual_windowWidth = window.getDefaultView().getSize().x;
	float actual_windowHeight = window.getDefaultView().getSize().y;

	//Set the character size to fit the window size
	float factor = actual_windowWidth / WindowWidth;
	notSelected.setCharacterSize(factor * 30);
	selected.setCharacterSize(factor * 30);
	float optionHeight = selected.getLocalBounds().height;

	unsigned n = 0;
	for (auto& opt : options)
	{
		opt.setCharacterSize(factor * 30);
		auto halfWidth = this->options.back().getGlobalBounds().width;
		sf::Vector2f pos(position.x * actual_windowWidth - opt.getGlobalBounds().width / 2, position.y * actual_windowHeight + optionHeight * n);
		opt.setPosition(pos);
		n++;
	}
}

void OptionSelect::draw(sf::RenderTarget* window)
{
	for (auto& text : options) {
		window->draw(text);
	}
}

void OptionSelect::setPos(sf::Vector2f position)
{
	this->position = position;
}

void OptionSelect::next()
{
	styleBefore();
	increment();
	styleAfter();
}

void OptionSelect::prev()
{
	styleBefore();
	decrement();
	styleAfter();
}

bool OptionSelect::update(sf::RenderWindow& window)
{
	auto mousePos = sf::Mouse::getPosition(window);

	//Find the hovered option
	for (auto& text : options)
	{
		//If an option is under the cursor...
		if (text.getGlobalBounds().contains(sf::Vector2f(mousePos)))
		{

			//Remove 'selected' style from currently selected item
			styleBefore();

			//Update selection pointer
			cursorPtr = &text;
			
			//Set 'selected' style on the currently selected item
			styleAfter();

			return true;
		}
	}
	return false;
}