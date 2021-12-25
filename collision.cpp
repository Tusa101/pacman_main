#include <SFML/Graphics.hpp>
#include "collision.h"


bool Collision::CheckCollision(Collision& other, float push) const
{
	sf::Vector2f other_position = other.GetPosition();
	sf::Vector2f other_half_size = other.GetHalfSize();
	sf::Vector2f this_position = GetPosition();
	sf::Vector2f this_half_size = GetHalfSize();

	float delta_x = other_position.x - this_position.x;
	float delta_y = other_position.y - this_position.y;

	float intersect_x = abs(delta_x) - (other_half_size.x + this_half_size.x);
	float intersect_y  = abs(delta_y) - (other_half_size.y + this_half_size.y);

	if (intersect_x < 0.0f && intersect_y < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if(abs(intersect_x) < abs(intersect_y))
		{
			if(delta_x > 0.0f)
			{
				//Move(intersect_x * (1.0f - push), 0.0f);
				other.Move(-intersect_x * push, 0.0f);
			}
			else
			{
				//Move(-intersect_x * (1.0f - push), 0.0f);
				other.Move(intersect_x * push, 0.0f);
			}
		}
		else
		{
			if (delta_y > 0.0f)
			{
				//Move(0.0f, intersect_y * (1.0f - push));
				other.Move(0.0f, -intersect_y * push);
			}
			else
			{
				//Move(0.0f, -intersect_y * (1.0f - push));
				other.Move(0.0f, intersect_y * push);
			}
		}
		return true;
	}


	return false;
}
