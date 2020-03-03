#include "OptionSelectMM.h"


OptionSelectMM::OptionSelectMM(std::vector<std::string> options, sf::Font& font, sf::Vector2u position, State* state)
	:
	OptionSelect(options, font, position),
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