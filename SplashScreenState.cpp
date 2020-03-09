#include "SplashScreenState.h"



SplashScreenState::SplashScreenState(sf::RenderWindow* window, AssetManager& manager, MenuState* menuState)
	:
	State(window, manager),
	currentDuration(sf::Time::Zero),
	wholeDuration(sf::seconds(SplashScreenImage_d)),
	fadeIn(sf::seconds(SplashScreenImage_fi))
{
	this->menuState = menuState;
	pausable = false;
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
#ifdef NDEBUG
	//Go fullscreen
	sf::ContextSettings contextSettings(0U, 0U, 8U, 1U, 1U, 0U, false);

	//Find screen width/height
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	sf::VideoMode vMode(desktop.right, desktop.bottom);

	//Recreate window fullscreen
	window->create(vMode, Title, sf::Style::Fullscreen, contextSettings);
	window->setKeyRepeatEnabled(true);
	window->setVerticalSyncEnabled(true);
#else
	sf::ContextSettings contextSettings(0U, 0U, 8U, 1U, 1U, 0U, false);
	sf::VideoMode vMode(960, 540);
	window->create(vMode, Title, sf::Style::Titlebar | sf::Style::Close, contextSettings);
	window->setKeyRepeatEnabled(true);
	window->setVerticalSyncEnabled(true);
#endif
	menuState->resize();

	//Exit state
	setting = Exiting;
}

void SplashScreenState::update(const float& dt)
{
	if (setting == Running)
	{
		updateInput(dt);
		currentDuration += sf::seconds(dt);
		if(D_COUT)
			std::cout << "duration: " << currentDuration.asSeconds() << "\n";
		//TODO: Add updateable elements
		if (currentDuration.asSeconds() < fadeIn.asSeconds())
		{
			image.setColor(sf::Color(255, 255, 255, 255 * currentDuration.asSeconds() / fadeIn.asSeconds()));
		}
		else
		{
			image.setColor(sf::Color(255, 255, 255, 255));
			if (currentDuration.asSeconds() > wholeDuration.asSeconds())
				this->endState();
		}
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

int SplashScreenState::handleEvent(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		window->close();
		break;
	case sf::Event::Resized:
		perror("Resized during splashScreen!\n");
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
			endState();
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
	return -1;
}
