#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>

class OptionSelect
{
private:
	sf::Vector2u position;
	unsigned optionHeight;


	//MODEL
	sf::Text notSelected, selected;


protected:
	sf::Text* cursorPtr; 
	std::vector<sf::Text> options;
	sf::RenderWindow& window;

	void styleBefore();
	void styleAfter();
	void increment();
	void decrement();
public:
	OptionSelect(std::vector<std::string> options, sf::Font& font, sf::Vector2u position, sf::RenderWindow& window);

	void draw(sf::RenderTarget* window);
	void setPos(sf::Vector2u position);
	void next();
	void prev();
	bool update(sf::RenderWindow& window);
	virtual void select() = 0;
	virtual void ifSelect() = 0; //Use to select by clicking
};
