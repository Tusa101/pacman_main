#pragma once
#include "collision.h"
#include <SFML/Graphics.hpp>
class Point
{
public:
	Point() :x_(0), y_(0) {}
	Point(const float& x, const float& y) : x_(x), y_(y) {}
	const float GetX() const { return x_; }
	const float GetY() const { return y_; }
	void SetX(const float& x) { x_ = x; }
	void SetY(const float& y) { y_ = y; }
private:
	float x_;
	float y_;
};


class Entity
{
public:
	Entity(const sf::Texture* texture, sf::Vector2f position, const int& left_upper_x, const int& left_upper_y, const int& right_lower_x, const int& right_lower_y, const char& type);
	void Draw(sf::RenderWindow& window) const;
	sf::Vector2f GetPosition() { return body_.getPosition(); }
	Collision GetCollision() { return Collision(body_); }
	char GetType() const { return type_; }
private:
	sf::RectangleShape body_;
	char type_;
	

};
