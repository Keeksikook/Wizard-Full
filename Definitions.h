#pragma once

/*
	_d => duration
	_fc => frame count

	_fi => fadein time

*/

//Code snippets
#define PrintView std::cout << "[" << window->getView().getSize().x << " : " << window->getView().getSize().y << "]\n";
#define PrintVector2f std::cout << "[" << v.x << " : " << v.y << "]\n";


//GameSettings
constexpr auto Title = "Wizardry!";
constexpr auto WorldSizeX = 16 * 20; //320
constexpr auto WorldSizeY = 9 * 20; //180
constexpr auto WindowWidth = 960;
constexpr auto WindowHeight = 540;

constexpr auto PlayerSpeed = 3.f;
constexpr auto PlayerAccel = 40.f;
constexpr auto PlayerDecel = 8.f;
constexpr auto PlayerHP = 2000.f;

constexpr auto ExploderHP = 1000;
constexpr auto ExploderDMG = 2000;
constexpr auto ExploderRange = 8;
constexpr auto ExploderSpeed = 35.f;
constexpr auto ExploderChargeTime = 1.2f;



//Switches
constexpr auto D_COUT = false; //Cout debugging messages


//Timings
constexpr auto SplashScreenImage_d = 4.f;
constexpr auto SplashScreenImage_fi = 0.75f;


//Textures
constexpr auto MainMenuBackground = "Assets/Images/mainmenu.png";
constexpr auto SplashScreenImage = "Assets/Images/splashscreen.png";
constexpr auto Grass = "Assets/Images/grass.png";


//Animations
constexpr auto Torch = "Assets/Animations/torch.png";
constexpr auto Torch_fc = 8;
constexpr auto Torch_d = 1.2f;

constexpr auto Test = "Assets/Animations/test.png";
constexpr auto Test_fc = 6;
constexpr auto Test_d = 6.f;

constexpr auto WizardIdle = "Assets/Animations/wizardidle.png";
constexpr auto WizardIdle_fc = 4;
constexpr auto WizardIdle_d = .9f;

constexpr auto WizardRight = "Assets/Animations/wizard-right.png";
constexpr auto WizardRight_fc = 4;
constexpr auto WizardRight_d = .7f;

constexpr auto WizardLeft = "Assets/Animations/wizard-left.png";
constexpr auto WizardLeft_fc = 4;
constexpr auto WizardLeft_d = .7f;

constexpr auto ExploderIdle = "Assets/Animations/exploderidle.png";
constexpr auto ExploderIdle_fc = 10;
constexpr auto ExploderIdle_d = .7f;

constexpr auto ExploderMove = "Assets/Animations/exploderidle.png";
constexpr auto ExploderMove_fc = 10;
constexpr auto ExploderMove_d = .7f;

constexpr auto ExploderCharging = "Assets/Animations/exploder-charging.png";
constexpr auto ExploderCharging_fc = 10;
constexpr auto ExploderCharging_d = ExploderChargeTime;

constexpr auto ExploderDeath = "Assets/Animations/exploderidle.png";
constexpr auto ExploderDeath_fc = 10;
constexpr auto ExploderDeath_d = .7f;

constexpr auto ExploderExplosion = "Assets/Animations/exploder-explosion.png";
constexpr auto Explosion_fc = 10;
constexpr auto Explosion_d = .3f;


//Fonts
constexpr auto Khand = "Assets/Fonts/khand.ttf";
constexpr auto Arial = "Assets/Fonts/arial.ttf";


//Sound buffers


//Music


