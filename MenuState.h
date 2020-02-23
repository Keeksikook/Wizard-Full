#pragma once
#include"State.h"
#include"OptionSelect.h"

class MenuState :
	public State
{
private:
	/*All necessary variables here*/
	OptionSelect optionSelect;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
public:
	MenuState(sf::RenderWindow* window, sf::Event& event, AssetManager& manager);
	virtual ~MenuState();

	//Functions
	void endState() override;
	void updateInput(const float& dt) override;
	void update(const float& dt) override;
	void draw(sf::RenderTarget* target = nullptr) override;
};