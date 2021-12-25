#include <SFML/Graphics.hpp>
#include "entity_new.h"

Entity::Entity(const sf::Texture* texture, sf::Vector2f position, const int& left_upper_x, const int& left_upper_y, const int& right_lower_x, const int& right_lower_y, const char& type ):
type_(type)
{
	body_.setSize({ 32.f, 32.f });
	body_.setTexture(texture);
	body_.setTextureRect(sf::IntRect(left_upper_x, left_upper_y, right_lower_x, right_lower_y));
	body_.setPosition(position.x * 32, position.y * 32);
}

void Entity::Draw(sf::RenderWindow& window) const
{
	window.draw(body_);
}
