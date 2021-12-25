#include <SFML/Graphics.hpp>
#include "entity_new.h"
using namespace sf;
void DrawMap(std::vector<Entity> v_wall, sf::RenderWindow& window)
{
	
}

std::vector<Entity> MapConstructor(const std::vector<std::string>& map,const Texture* texture, sf::RenderWindow& window, const int& width)
{
	std::vector<Entity> wall_coords = {};
	auto iterator = map.begin();
	int height_cnt = 0;
	
	for (; iterator < map.end(); ++iterator)
	{
		for (int i = 0; i < width; ++i)
		{
			switch ((*iterator)[i])
			{
			case '1':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 0, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '2':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 17, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '3':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 33, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '4':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 49, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '5':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 65, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '6':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 81, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '7':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 97, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '8':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 113, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '9':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 129, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case 'A':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 145, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case 'B':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 161, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case 'C':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 177, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case 'D':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 193, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case 'E':
			{
				auto wall = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 209, 0, 16, 16, (*iterator)[i]);
				wall_coords.push_back(wall);
			}break;
			case '.':
			{
				auto dot = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 0, 16, 16, 16, (*iterator)[i]);
				wall_coords.push_back(dot);
			}break;
			case 'o':
			{
				auto cheat = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 16, 16, 16, 16, (*iterator)[i]);
				wall_coords.push_back(cheat);
			}break;
			case '-':
			{
				auto door = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 33, 16, 16, 16, (*iterator)[i]);
				wall_coords.push_back(door);
			}break;
			default:
			{
				auto empty = Entity(texture, { static_cast<float>(i),static_cast<float>(height_cnt) }, 70, 16, 16, 16, (*iterator)[i]);
				wall_coords.push_back(empty);
			}
			}
		}
		height_cnt++;
	}


	return wall_coords;
}