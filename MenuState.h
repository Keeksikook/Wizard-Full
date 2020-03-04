#pragma once
#include"State.h"
#include"OptionSelectMM.h"
#include"AnimatedObject.h"

class MenuState :
	public State
{
private:
	/*All necessary variables here*/
	OptionSelectMM optionSelect;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	AnimatedObject torch, test;
public:
	MenuState(sf::RenderWindow* window, AssetManager& manager);
	virtual ~MenuState();

	//Functions
	void endState() override;
	void updateInput(const float& dt) override;
	void update(const float& dt) override;
	void draw(sf::RenderTarget* target = nullptr) override;
	virtual void handleEvent(sf::Event& event);
};