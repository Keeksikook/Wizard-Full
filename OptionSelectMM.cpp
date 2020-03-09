#include "OptionSelectMM.h"


OptionSelectMM::OptionSelectMM(std::vector<std::string> options, sf::Font& font, sf::Vector2f position, State* state, sf::RenderWindow& window)
	:
	OptionSelect(options, font, position, window),
	state(state)
{
}

unsigned OptionSelectMM::select()
{
	if (cursorPtr == &options[0]) { //New Game
		return 0;
	}
	else if (cursorPtr == &options[1]) { //About
		return 1;
	}
	else { //Exit
		return 2;
	}
}

unsigned OptionSelectMM::ifSelect()
{
	//This is to be called, when the mouse is clicked.
	//If the update selects an option, activate it.
	//If dont select anything, return -1, otherwise return the option index
	if (update(window))
	{
		return select();
	}
	return -1;
}
