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
#define Title "Wizardry!"
#define WorldSizeX 16*20 //320
#define WorldSizeY 9*20 //180
#define WindowWidth 960
#define WindowHeight 540
#define PlayerSpeed 3.f
#define PlayerAccel 8.f
#define PlayerDecel 12.f
#define AntiSlip true

//Switches
#define D_COUT false //Cout debugging messages


//Timings
#define SplashScreenImage_d 4.f
#define SplashScreenImage_fi 0.75f


//Textures
#define MainMenuBackground "Assets/Images/mainmenu.png"
#define SplashScreenImage "Assets/Images/splashscreen.png"
#define Grass "Assets/Images/grass.png"


//Animations
#define Torch "Assets/Animations/torch.png"
#define Torch_fc 8
#define Torch_d 1.2f

#define Test "Assets/Animations/test.png"
#define Test_fc 6
#define Test_d 6.f

#define WizardIdle "Assets/Animations/wizardidle.png"
#define WizardIdle_fc 4
#define WizardIdle_d 3.f


//Fonts
#define Khand "Assets/Fonts/khand.ttf"
#define Arial "Assets/Fonts/arial.ttf"


//Sound buffers


//Music


