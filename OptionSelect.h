#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>

class OptionSelect
{
private:
	sf::Text* cursorPtr; 
	sf::Vector2u position;
	std::vector<sf::Text> options;
	unsigned optionHeight;


	//MODEL
	sf::Text notSelected, selected;


	void styleBefore();
	void styleAfter();
	void increment();
	void decrement();
public:
	OptionSelect(std::vector<std::string> options, sf::Font& font, sf::Vector2u position);
	void draw(sf::RenderTarget* window);
	void setSize(sf::Vector2u position);
	void update();
	void next();

	void prev();
	void select();
};
