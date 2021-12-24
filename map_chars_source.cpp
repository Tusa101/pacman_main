#include "map_characteristics.h"
#include <SFML/Graphics.hpp>


void Entity::SetEntity(const float& x, const float& y, sf::RenderWindow& window)
{
	coords.SetX(x * 32);
	coords.SetY(y * 32);
	sprite_.setPosition(static_cast<float>(x) * 32, static_cast<float>(y) * 32);
	window.draw(sprite_);
}