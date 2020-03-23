#pragma once
#include"OptionSelectMM.h"
#include"AnimatedObject.h"

class MenuState :
	public State
{
private:
	/*All necessary variables here*/
	OptionSelectMM optionSelect;
	sf::Sprite backgroundSprite;
	AnimatedObject torch, test;
public:
	MenuState(sf::RenderWindow* window, AssetManager& manager);
	virtual ~MenuState();

	//Functions
	void endState() override;
	void updateInput(const float& dt) override;
	void update(const float& dt) override;
	void draw(sf::RenderTarget* target = nullptr) override;
	int handleEvent(sf::Event& event) override;

	std::string getType() override { return "MenuState"; }
	void resize();

};