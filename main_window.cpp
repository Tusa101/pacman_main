#include <SFML/Graphics.hpp>
#include <time.h>
#include "map_characteristics.h"
#include "pacman_character.h"
using namespace sf;

std::vector<Entity> MapConstructor(const std::vector<std::string>& map,const Texture& texture, sf::RenderWindow& window, const int& width);
static const int Height = 22;
static const int Width = 25;

int main()
{

	RenderWindow window(VideoMode(Width * 32, Height * 32), "Pacman");
	std::vector<std::string> map = {

		"6777777777778777777777774",
		"A...........A...........A", //17   13     //h:22 w:26
		"Ao5773.5773.9.5773.5773oA",
		"A.......................A",
		"A.573.2.577787773.2.573.A",
		"A.....A.....A.....A.....A",
		"D7774.E7773.9.5777C.6777B",
		"    A.A..... .....A.A    ",
		"7777B.9.6777-7774.9.D7777",
		"........A       A........",
		"77774.2.A       A.2.67777",
		"    A.A.D7777777B.A.A    ",
		"    A.A...........A.A    ",
		"6777B.9.577787773.9.D7774",
		"A...........A...........A",
		"A.574.57773.9.57773.673.A",
		"Ao..A.......P.......A..oA",
		"E73.9.5777778777773.9.57C",
		"A...........A...........A",
		"A.577777773.9.577777773.A",
		"A.......................A",
		"D77777777777777777777777B"
	};


	int direction = 0;
	int obstacles[4] = { 0, 0, 0, 0 };

	Texture texture_map, texture_pacman_right, texture_pacman_left, texture_pacman_up, texture_pacman_down;
	texture_map.loadFromFile("D:\\Проги\\pacman_main\\Debug\\images\\Map16.png");
	texture_pacman_right.loadFromFile("D:\\Проги\\pacman_main\\Debug\\images\\right.png");
	texture_pacman_left.loadFromFile("D:\\Проги\\pacman_main\\Debug\\images\\left.png");
	texture_pacman_up.loadFromFile("D:\\Проги\\pacman_main\\Debug\\images\\up.png");
	texture_pacman_down.loadFromFile("D:\\Проги\\pacman_main\\Debug\\images\\down.png");


	float start_x = 12 * 32, start_y = 16 * 32;


	Pacman pacman = Pacman(texture_pacman_right, start_x, start_y);
	
	Sprite sprite_pacman_right(texture_pacman_right);
	Sprite sprite_pacman_left(texture_pacman_left);
	Sprite sprite_pacman_up(texture_pacman_up);
	Sprite sprite_pacman_down(texture_pacman_down);
	while (window.isOpen())
	{		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type==Event::Closed)
			{
				window.close();
			}
			/*if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					window.close();
				}
				if (event.key.code == Keyboard::Left)
				{
					direction = 1;
				}
				if (event.key.code == Keyboard::Right)
				{
					direction = 0;
				}
				if (event.key.code == Keyboard::Up)
				{
					direction = 2;
				}
				if (event.key.code == Keyboard::Down)
				{
					direction = 3;
				}
			}*/
		}
		
		/////////// Drawing map ////////////////
		window.clear(Color::Black);
		auto wall_coords = MapConstructor(map, texture_map, window, Width);

		Collision collision1 = pacman.GetCollision();
		for (auto it = wall_coords.begin(); it < wall_coords.end(); ++it)
		{
			if ((*it).GetCoords().GetY() == pacman.GetCoords().GetY() + 32 && (*it).GetCoords().GetX() <= pacman.GetCoords().GetX()&& 32+ (*it).GetCoords().GetX() >= pacman.GetCoords().GetX()&& (*it).IsWall())
			{
				obstacles[3] = -1;
				continue;
			}
			if ((*it).GetCoords().GetY() == pacman.GetCoords().GetY() - 32 && (*it).GetCoords().GetX() <= pacman.GetCoords().GetX() && 32 + (*it).GetCoords().GetX() >= pacman.GetCoords().GetX() && (*it).IsWall())
			{
				obstacles[2] = -1;
				continue;
			}
			if ((*it).GetCoords().GetX() == pacman.GetCoords().GetX() + 32 && (*it).GetCoords().GetY() <= pacman.GetCoords().GetY() && 32 + (*it).GetCoords().GetY() >= pacman.GetCoords().GetY() && (*it).IsWall())
			{
				obstacles[0] = -1;
				continue;
			}
			if ((*it).GetCoords().GetX() == pacman.GetCoords().GetX() - 32 && (*it).GetCoords().GetY() <= pacman.GetCoords().GetY() && 32 + (*it).GetCoords().GetY() >= pacman.GetCoords().GetY() && (*it).IsWall())
			{
				obstacles[1] = -1;
			}
		}



		Event event1;
		int cnt = 0;
		while (window.pollEvent(event1))
		{
			
			for (int i = 0; i < 4; ++i)
			{
				if (obstacles[i]==-1)
				{
					cnt++;
				}
			}
			if(cnt == 2)
			{
				if (obstacles[0] == -1 && obstacles[1] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Down)
						{
							direction = 3;
						}
						if (event1.key.code == Keyboard::Up)
						{
							direction = 2;
						}
						if (event1.key.code == Keyboard::Left)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = -1;
						}
						break;
					}
				}


				if (obstacles[0] == -1 && obstacles[2] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Left)
						{
							direction = 1;
						}
						if (event1.key.code == Keyboard::Down)
						{
							direction = 3;
						}
						if (event1.key.code == Keyboard::Up)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = -1;
						}
						break;
					}
				}
				if (obstacles[0] == -1 && obstacles[3] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Left)
						{
							direction = 1;
						}
						if (event1.key.code == Keyboard::Up)
						{
							direction = 2;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Down)
						{
							direction = -1;
						}
						break;
					}
				}
				if (obstacles[1] == -1 && obstacles[2] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Down)
						{
							direction = 3;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = 0;
						}
						if (event1.key.code == Keyboard::Up)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Left)
						{
							direction = -1;
						}
						break;
					}
				}
				if (obstacles[1] == -1 && obstacles[3] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Up)
						{
							direction = 2;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = 0;
						}
						if (event1.key.code == Keyboard::Left)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Down)
						{
							direction = -1;
						}
						break;
					}
				}
				if (obstacles[2] == -1 && obstacles[3] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Left)
						{
							direction = 1;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = 0;
						}
						if (event1.key.code == Keyboard::Up)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Down)
						{
							direction = -1;
						}
						break;
					}

				}
				
			}
			
			if (cnt == 1)
			{
				if (obstacles[0] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Left)
						{
							direction = 1;
						}
						if (event1.key.code == Keyboard::Right || direction == 0)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Up)
						{
							direction = 2;
						}
						if (event1.key.code == Keyboard::Down)
						{
							direction = 3;
						}
						break;
					}
				}
				if (obstacles[1] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Left || direction == 1)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = 0;
						}
						if (event1.key.code == Keyboard::Up)
						{
							direction = 2;
						}
						if (event1.key.code == Keyboard::Down)
						{
							direction = 3;
						}
						break;
					}
				}
				if (obstacles[2] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Left)
						{
							direction = 1;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = 0;
						}
						if (event1.key.code == Keyboard::Up || direction == 2)
						{
							direction = -1;
						}
						if (event1.key.code == Keyboard::Down)
						{
							direction = 3;
						}
						break;
					}
				}
				if (obstacles[3] == -1)
				{
					if (event1.type == event1.KeyPressed)
					{
						if (event1.key.code == Keyboard::Left)
						{
							direction = 1;
						}
						if (event1.key.code == Keyboard::Right)
						{
							direction = 0;
						}
						if (event1.key.code == Keyboard::Up)
						{
							direction = 2;
						}
						if (event1.key.code == Keyboard::Down || direction == 3)
						{
							direction = -1;
						}
						break;
					}
				}
			}
			obstacles[0] = 0;
			obstacles[1] = 0;
			obstacles[2] = 0;
			obstacles[3] = 0;
			cnt = 0;
			
		}
		
	
		
		
		///////////////////////Drawing pacman movement //////////////////
			
		
		

		float velocity = 0.1f;
		switch (direction)
		{
		case 0:
		{

			pacman = pacman + Point(velocity, 0);
			pacman.SetSprite(sprite_pacman_right);
			pacman.SetEntity(window);
		}break;
		case 1:
		{
			pacman = pacman + Point(-velocity, 0);
			pacman.SetSprite(sprite_pacman_left);
			pacman.SetEntity(window);
		}break;
		case 2:
		{
			pacman = pacman + Point(0, -velocity);
			pacman.SetSprite(sprite_pacman_up);
			pacman.SetEntity(window);
		}break;
		case 3:
		{
			pacman = pacman + Point(0, velocity);
			pacman.SetSprite(sprite_pacman_down);
			pacman.SetEntity(window);
		}break;
		default:
		{
			pacman.SetSprite(sprite_pacman_right);
			pacman.SetEntity(window);
		}break;
		}
		
		
		
		window.display();
	}
	return 0;
}
