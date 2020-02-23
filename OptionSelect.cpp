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

OptionSelect::OptionSelect(std::vector<std::string> options, sf::Font& font, sf::Vector2u position)
	:
	position(position)
{
	//Non-Selected style
	notSelected.setFont(font);
	notSelected.setFillColor(sf::Color::White);
	notSelected.setOutlineColor(sf::Color::Black);
	notSelected.setStyle(sf::Text::Italic);
	notSelected.setOutlineThickness(1.f);
	notSelected.setString("#NOTSELECTED#");
	////

	//Find the height of an option using the non-selected text
	optionHeight = notSelected.getGlobalBounds().height;

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
		static unsigned n = 0;
		this->options.push_back(notSelected);
		this->options.back().setFont(font);
		this->options.back().setString(txt);
		this->options.back().setPosition(position.x - this->options.back().getGlobalBounds().width / 2, position.y + optionHeight * n);
		n++;
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
}

void OptionSelect::draw(sf::RenderTarget* window)
{
	unsigned n = 0;
	for (auto& text : options) {
		window->draw(text);
	}
	
}

void OptionSelect::setSize(sf::Vector2u position)
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
