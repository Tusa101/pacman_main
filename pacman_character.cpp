#include "pacman_character.h"
#include "map_characteristics.h"
void Pacman::SetEntity(sf::RenderWindow& window)
{
	sprite_.setPosition(coords_.GetX(), coords_.GetY());
	window.draw(sprite_);
}

Pacman& Pacman::operator+(const Point& other)
{
	coords_.SetX(coords_.GetX() + other.GetX());
	coords_.SetY(coords_.GetY() + other.GetY());
	return *this;
}

Pacman& Pacman::operator=(const Pacman& pacman)
{
	coords_.SetX(pacman.GetCoords().GetX());
	coords_.SetY(pacman.GetCoords().GetY());
	return *this;
}
