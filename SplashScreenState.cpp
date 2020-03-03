#include "SplashScreenState.h"

SplashScreenState::SplashScreenState(sf::RenderWindow* window, sf::Event& event, AssetManager& manager)
	:
	State(window, event, manager),
	currentDuration(sf::Time::Zero),
	wholeDuration(sf::seconds(SplashScreenImage_d)),
	fadeIn(sf::seconds(SplashScreenImage_fi))
{
	image.setTexture(manager.texture("SplashScreenImage"));
	image.setColor(sf::Color(0, 0, 0, 0));
}

SplashScreenState::~SplashScreenState()
{
}

void SplashScreenState::checkQuit()
{
	//TODO
}

void SplashScreenState::endState()
{
}

void SplashScreenState::update(const float& dt)
{
	if (setting == Running)
	{
		updateInput(dt);
		currentDuration += sf::seconds(dt);

		//TODO: Add updateable elements
		if (currentDuration.asSeconds() < fadeIn.asSeconds())
			image.setColor(sf::Color(255, 255, 255, 255 * currentDuration.asSeconds() / fadeIn.asSeconds()));
		else
			image.setColor(sf::Color(255, 255, 255, 255));
	}
}

void SplashScreenState::updateInput(const float& dt)
{
	checkQuit();
}

void SplashScreenState::draw(sf::RenderTarget* target)
{
	if (!target)
		target = window;
	//TODO: Add drawable elements

	target->draw(image);
}

void SplashScreenState::handleEvents()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			//Fix view 
		{ //This block is needed to avoid C2360
			sf::FloatRect view(0, 0, event.size.width, event.size.height);
			window->setView(sf::View(view));
		}
		break;
		case sf::Event::MouseMoved:
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::P)
			{
				togglePause();
			}
			if (event.key.code == sf::Keyboard::Pause)
			{
				togglePause();
			}
			if (event.key.code == sf::Keyboard::Enter)
			{
			}
			else if (event.key.code == sf::Keyboard::BackSpace)
			{
				setting = State::Exiting;
			}
			else if (event.key.code == sf::Keyboard::W)
			{
			}
			else if (event.key.code == sf::Keyboard::S)
			{
			}
			else if (event.key.code == sf::Keyboard::A)
			{
			}
			else if (event.key.code == sf::Keyboard::D)
			{
			}
			else if (event.key.code == sf::Keyboard::Up)
			{
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
			}
			else if (event.key.code == sf::Keyboard::Left)
			{
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
			}
			break;
		}
	}
}
