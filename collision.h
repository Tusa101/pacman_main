#pragma once
#include <SFML/Graphics.hpp>


class Collision
{
public:
	Collision(sf::Sprite& body):body_(body){}
	~Collision(){}

	void Move(float dx, float dy) { body_.move(dx, dy); }

	bool CheckCollision(Collision& other, float push);
	sf::Vector2f GetPosition() { return body_.getPosition(); }
	sf::Vector2f GetHalfSize() { return sf::Vector2f{32,32} / 2.0f; }
private:
	sf::Sprite& body_;
};

