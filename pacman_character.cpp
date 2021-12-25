#include "pacman_character.h"

Pacman::Pacman(const sf::Texture* texture, const sf::Vector2f& position):
position_(position)
{
	body_.setSize({ 32,32 });
	body_.setTexture(texture);
}

void Pacman::Draw(sf::RenderWindow& window)
{
	body_.setPosition(position_.x, position_.y);
	window.draw(body_);
}

void Pacman::SetPosition(sf::Vector2f position)
{
	position_.x += position.x;
	position_.y += position.y;
}

void Pacman::ChangeTexture(const sf::Texture* texture)
{
	body_.setSize({ 32,32 });
	body_.setTexture(texture);
}
