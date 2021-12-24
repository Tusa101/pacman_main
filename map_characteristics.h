#pragma once
#include "collision.h"
#include <SFML/Graphics.hpp>
class Point
{
public:
	Point():x_(0),y_(0){}
	Point(const float& x, const float& y): x_(x), y_(y){}
	const float GetX() const  { return x_; }
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
	Entity(const sf::Texture& texture,const int& left_upper_x,const int& left_upper_y, const int& right_lower_x, const int& right_lower_y,const char& type):
	sprite_(texture)
	{
		if(type == '.')
		{
			is_wall_ = false;
			dot_or_not_ = true;
		}
		if (type == 'o')
		{
			is_wall_ = false;
			cheat_or_not_ = true;
		}
		if (type == '-')
		{
			is_wall_ = false;
			door_or_not_ = true;
		}
		if (type != '.' && type != 'o'&& type != '-'&& type != ' ')
		{
			is_wall_ = true;
		}
		sprite_.setTextureRect(sf::IntRect(left_upper_x, left_upper_y,right_lower_x,right_lower_y));
		sprite_.setScale(2.f, 2.f);
	}
	Collision GetCollision() { return Collision(sprite_); }
	sf::Sprite GetSprite() const { return sprite_; }
	void SetEntity(const float& x, const float& y, sf::RenderWindow& window);
	const Point GetCoords() const { return coords; }
	const bool IsWall() const { return is_wall_; }
	const bool IsDot() const { return dot_or_not_; }
	const bool IsDoor() const { return door_or_not_; }
	const bool IsCheat() const { return cheat_or_not_; }

private:
	sf::Sprite sprite_;
	Point coords{};
	bool is_wall_ = false;
	bool dot_or_not_ = false;
	bool cheat_or_not_ = false;
	bool door_or_not_ = false;
};

