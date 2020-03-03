#pragma once
#include "OptionSelect.h"
#include "State.h"
class OptionSelectMM :
	public OptionSelect
{
private:
	State* state;
public:
	OptionSelectMM(std::vector<std::string> options, sf::Font& font, sf::Vector2u position, State* state);
	void select() override;
};

