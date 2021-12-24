#include <SFML/Graphics.hpp>
#include "map_characteristics.h"
using namespace sf;

std::vector<Entity> MapConstructor(const std::vector<std::string>& map,const Texture& texture, sf::RenderWindow& window, const int& width)
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
				auto wall = Entity(texture, 0, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '2':
			{
				auto wall = Entity(texture, 17, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '3':
			{
				auto wall = Entity(texture, 33, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '4':
			{
				auto wall = Entity(texture, 49, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '5':
			{
				auto wall = Entity(texture, 65, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '6':
			{
				auto wall = Entity(texture, 81, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '7':
			{
				auto wall = Entity(texture, 97, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '8':
			{
				auto wall = Entity(texture, 113, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '9':
			{
				auto wall = Entity(texture, 129, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case 'A':
			{
				auto wall = Entity(texture, 145, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case 'B':
			{
				auto wall = Entity(texture, 161, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case 'C':
			{
				auto wall = Entity(texture, 177, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case 'D':
			{
				auto wall = Entity(texture, 193, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case 'E':
			{
				auto wall = Entity(texture, 209, 0, 16, 16, (*iterator)[i]);
				wall.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(wall);
			}break;
			case '.':
			{
				auto dot = Entity(texture, 0, 16, 16, 16, (*iterator)[i]);
				dot.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(dot);
			}break;
			case 'o':
			{
				auto cheat = Entity(texture, 16, 16, 16, 16, (*iterator)[i]);
				cheat.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(cheat);
			}break;
			case '-':
			{
				auto door = Entity(texture, 33, 16, 16, 16, (*iterator)[i]);
				door.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(door);
			}break;
			default:
			{
				auto empty = Entity(texture, 70, 16, 16, 16, (*iterator)[i]);
				empty.SetEntity(static_cast<float>(i), static_cast<float>(height_cnt), window);
				wall_coords.push_back(empty);
			}
			}
		}
		height_cnt++;
	}


	return wall_coords;
}