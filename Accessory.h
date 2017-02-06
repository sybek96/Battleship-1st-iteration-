#pragma once
#include <SFML\Graphics.hpp>

class Accessory
{
public:
	Accessory();
	~Accessory();
private:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	sf::Texture m_texture;
};

