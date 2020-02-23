#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <map>

class AssetManager
{
private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::SoundBuffer> soundBuffers;
public:
	AssetManager() {}
	sf::Texture& texture(std::string name) { return textures[name]; }
	sf::Font& font(std::string name) { return fonts[name]; }
	sf::SoundBuffer& buffer(std::string name) { return soundBuffers[name]; }
	
	void loadTexture(std::string name, std::string filePath) {
		textures[name] = sf::Texture();
		textures[name].loadFromFile(filePath);
	}
	void loadFont(std::string name, std::string filePath) {
		fonts[name] = sf::Font();
		fonts[name].loadFromFile(filePath);
	}
	void loadBuffer(std::string name, std::string filePath) {
		soundBuffers[name] = sf::SoundBuffer();
		soundBuffers[name].loadFromFile(filePath);
	}
};

