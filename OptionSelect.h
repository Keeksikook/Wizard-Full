#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include"Definitions.h"

class OptionSelect
{
private:
	sf::Vector2f position;


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
	OptionSelect(std::vector<std::string> options, sf::Font& font, sf::Vector2f position, sf::RenderWindow& window);

	void reSize();
	void draw(sf::RenderTarget* window);
	void setPos(sf::Vector2f position);
	void next();
	void prev();
	bool update(sf::RenderWindow& window);
	virtual unsigned select() = 0;
	virtual unsigned ifSelect() = 0; //Use to select by clicking
};
