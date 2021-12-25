#pragma once
#include <SFML/Graphics.hpp>


class Collision
{
public:
	Collision(sf::RectangleShape& body):body_(body){}
	~Collision(){}

	void Move(const float& dx, const float& dy) const { body_.move(dx, dy); }

	bool CheckCollision(Collision& other, float push) const;
	sf::Vector2f GetPosition() const { return body_.getPosition(); }
	sf::Vector2f GetHalfSize() const { return body_.getSize() / 2.0f; }
private:
	sf::RectangleShape& body_;
};

