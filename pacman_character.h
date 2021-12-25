#pragma once
#include <SFML/Graphics.hpp>
#include "collision.h"


class Pacman
{
public:
	Pacman(const sf::Texture* texture, const sf::Vector2f& position);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() const { return body_.getPosition(); }
	Collision GetCollision() { return Collision(body_); }
	void SetPosition(sf::Vector2f position);
	void ChangeTexture(const sf::Texture* texture);
private:
	sf::RectangleShape body_;
	sf::Vector2f position_;
};
