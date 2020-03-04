#include "OptionSelectMM.h"


OptionSelectMM::OptionSelectMM(std::vector<std::string> options, sf::Font& font, sf::Vector2u position, State* state, sf::RenderWindow& window)
	:
	OptionSelect(options, font, position, window),
	state(state)
{
}

void OptionSelectMM::select()
{
	if (cursorPtr == &options[0]) { //New Game

	}
	else if (cursorPtr == &options[1]) { //About

	}
	else { //Exit
		state->setting = State::Exiting;
	}
}

void OptionSelectMM::ifSelect()
{
	//This is to be called, when the mouse is clicked.
	//If the update selects an option, activate it.
	if (update(window))
		select();
}
