#pragma once
#include <SFML/Graphics.hpp>
#include "map_characteristics.h"
#include "collision.h"


class Pacman
{
public:
	Pacman(const sf::Texture& texture, const float& x, const float& y) : sprite_(texture), coords_({ x,y }) {}
	Pacman(const Pacman& pacman) :coords_({pacman.GetCoords().GetX(), pacman.GetCoords().GetY()}){}
	sf::Sprite GetSprite() const { return sprite_; }
	void SetSprite(const sf::Sprite& sprite) { sprite_ = sprite; }

	void SetEntity(sf::RenderWindow& window);
	Point GetCoords() const { return coords_; }
	Pacman& operator+ (const Point& other);
	Pacman& operator= (const Pacman& pacman);

	Collision GetCollision() { return Collision(sprite_); }
private:
	sf::Sprite sprite_;
	Point coords_{};
};
