#pragma once
#include "SFML/Audio.hpp"
#include "Animation.h"
#include <map>

class AssetManager
{
private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::SoundBuffer> soundBuffers;
	std::map<std::string, Animation> animations;
public:
	AssetManager() {}

	sf::Texture& texture(std::string name) { return textures[name]; }
	sf::Font& font(std::string name) { return fonts[name]; }
	sf::SoundBuffer& buffer(std::string name) { return soundBuffers[name]; }
	Animation& animation(std::string name) { return animations[name]; }
	
	void loadTexture( std::string filePath) {
		textures[filePath] = sf::Texture();
		textures[filePath].loadFromFile(filePath);
	}
	void loadFont(std::string filePath) {
		fonts[filePath] = sf::Font();
		fonts[filePath].loadFromFile(filePath);
	}
	void loadBuffer( std::string filePath) {
		soundBuffers[filePath] = sf::SoundBuffer();
		soundBuffers[filePath].loadFromFile(filePath);
	}
	void loadAnimation(std::string filePath, float duration, unsigned frameCount) {
		animations[filePath] = { duration, sf::Texture(), frameCount };
		animations[filePath].texture.loadFromFile(filePath);
	}
};

