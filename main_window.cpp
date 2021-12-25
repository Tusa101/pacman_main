#include <SFML/Graphics.hpp>
#include "pacman_character.h"
#include "entity_new.h"
using namespace sf;

std::vector<Entity> MapConstructor(const std::vector<std::string>& map,const Texture* texture, sf::RenderWindow& window, const int& width);
static const int Height = 22;
static const int Width = 25;
static int coll_check = -1;
int main()
{

	RenderWindow window(VideoMode(Width * 32 + 10, Height * 32), "Pacman");
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

	Pacman pacman = Pacman(&texture_pacman_right, { start_x, start_y });
	

	while (window.isOpen())
	{		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type==Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
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
			}
		}
		
		/////////// Drawing map ////////////////
		window.clear(Color::Black);
		
		Collision collision = pacman.GetCollision();
		auto wall_coords = MapConstructor(map, &texture_map, window, Width);
		sf::Vector2f coll_coords = {};
		int collision_cell = -1;
		for (auto it = wall_coords.begin(); it < wall_coords.end(); ++it)
		{
			if ((*it).GetType()!='.'&& (*it).GetType() != 'o' && (*it).GetType() != ' ')
			{
				if ((*it).GetCollision().CheckCollision(collision, 1.0f))
				{
					coll_coords = { (*it).GetPosition().x, (*it).GetPosition().y };
				}
			}
			
			
		}
		if(coll_coords.x == pacman.GetPosition().x+32 && coll_coords.y <= pacman.GetPosition().y && 32 + coll_coords.y >= pacman.GetPosition().y)
		{
			collision_cell = 0;
		}
		if (coll_coords.x == pacman.GetPosition().x + 32 && coll_coords.y - 32 <= pacman.GetPosition().y &&  coll_coords.y >= pacman.GetPosition().y)
		{
			collision_cell = 0;
		}

		if (coll_coords.x == pacman.GetPosition().x -32&& coll_coords.y <= pacman.GetPosition().y && 32 + coll_coords.y >= pacman.GetPosition().y)
		{
			collision_cell = 1;
		}
		if (coll_coords.x == pacman.GetPosition().x - 32 && coll_coords.y <= pacman.GetPosition().y -32 &&  coll_coords.y >= pacman.GetPosition().y)
		{
			collision_cell = 1;
		}

		if (coll_coords.x <= pacman.GetPosition().x && 32 + coll_coords.x >= pacman.GetPosition().x && coll_coords.y == pacman.GetPosition().y + 32)
		{
			collision_cell = 3;
		}
		if (coll_coords.x - 32 <= pacman.GetPosition().x && coll_coords.x >= pacman.GetPosition().x && coll_coords.y == pacman.GetPosition().y + 32)
		{
			collision_cell = 3;
		}
		if (coll_coords.x <= pacman.GetPosition().x && 32 + coll_coords.x >= pacman.GetPosition().x && coll_coords.y == pacman.GetPosition().y - 32)
		{
			collision_cell = 2;
		}
		if (coll_coords.x -32 <= pacman.GetPosition().x &&  coll_coords.x >= pacman.GetPosition().x && coll_coords.y == pacman.GetPosition().y - 32)
		{
			collision_cell = 2;
		}
		///////////////////////Drawing pacman movement //////////////////
		
		for (auto it = wall_coords.begin(); it < wall_coords.end(); ++it)
		{
			(*it).Draw(window);
		}

		
		float velocity = 1.3f;
		if(direction == 0)
		{
			if (collision_cell != 0)
			{
				pacman.SetPosition({ velocity, 0 });
			}
			pacman.ChangeTexture(&texture_pacman_right);
			pacman.Draw(window);
		}
		if (direction == 1)
		{
			if (collision_cell != 1)
			{
				pacman.SetPosition({ -velocity, 0 });

			}
			pacman.ChangeTexture(&texture_pacman_left);
			pacman.Draw(window);
		}
		if (direction == 2)
		{
			if (collision_cell != 2)
			{
				pacman.SetPosition({ 0, -velocity });
			}
			pacman.ChangeTexture(&texture_pacman_up);
			pacman.Draw(window);
		}
		if (direction == 3)
		{
			if (collision_cell != 3)
			{
				pacman.SetPosition({ 0, velocity });
			}
			pacman.ChangeTexture(&texture_pacman_down);
			pacman.Draw(window);
		}
		if (pacman.GetPosition().x >= 26 * 32)
		{
			pacman.SetPosition({ -pacman.GetPosition().x-35,0 });
		}
		else
		{
			if (pacman.GetPosition().x <= -35)
			{
				pacman.SetPosition({ 26 * 32 +10,0 });
			}
		}


		
		window.display();
	}
	return 0;
}
