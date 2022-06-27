#include "map(level edditor).h"
#include "constants.h"
void map_level_edditor::init_map() //this part creates an array of squares to that the user may click apon them to chane them this is what the foreloops are to create each square and give it values
{
	U_C uc;
	uc.setval();
	double yvile = uc.menu_resolution.gety() / 16;
	double xvile = uc.menu_resolution.getx() / 20;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			/*
			std::cout << i << "cool" << j << std::endl;
			std::cout << uc.menu_resolution.getx() << "cool" << uc.menu_resolution.gety() << std::endl;
			std::cout << uc.menu_resolution.getx()/20 << "cool" << uc.menu_resolution.gety()/16 << std::endl;
			*/
			map[i][j].points[0].setx(i*(uc.menu_resolution.getx() / 20));
			map[i][j].points[1].setx(i*(uc.menu_resolution.getx() / 20));
			map[i][j].points[2].setx(i*(uc.menu_resolution.getx() / 20) + (uc.menu_resolution.getx() / 20));
			map[i][j].points[3].setx(i*(uc.menu_resolution.getx() / 20) + (uc.menu_resolution.getx() / 20));

			map[i][j].points[0].sety(j*(uc.menu_resolution.gety() /	16));
			map[i][j].points[1].sety(j*(uc.menu_resolution.gety() / 16) + (uc.menu_resolution.gety() / 16));
			map[i][j].points[2].sety(j*(uc.menu_resolution.gety() / 16) + (uc.menu_resolution.gety() / 16));
			map[i][j].points[3].sety(j*(uc.menu_resolution.gety() / 16));

			map[i][j].update_drawn_element();
		}
	}
};
void map_level_edditor::print_map(sf::RenderWindow* windowpointer)
{
	// this is inefficent it only needs to be done once (the 2 lines imediatly following this one also applies to function above with same lines of code)
	U_C uc;
	uc.setval();
	//the forloops are so that the squares are looked through
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			/*
			std::cout << map[i][j].points[0].getx() << " cheese test " << map[i][j].points[0].gety() << std::endl;
			std::cout << map[i][j].points[1].getx() << " cheese test " << map[i][j].points[1].gety() << std::endl;
			std::cout << map[i][j].points[2].getx() << " cheese test " << map[i][j].points[2].gety() << std::endl;
			std::cout << map[i][j].points[3].getx() << " cheese test " << map[i][j].points[3].gety() << std::endl;
			map[i][j].update_drawn_element();
			map[i][j].drawn_element[0].color = sf::Color::Red;
			map[i][j].drawn_element[1].color = sf::Color::Red;
			map[i][j].drawn_element[2].color = sf::Color::Red;
			map[i][j].drawn_element[3].color = sf::Color::Red;
			map[i][j].drawn_element[1].color = sf::Color::Red;
			map[i][j].drawn_element[2].color = sf::Color::Red;
			map[i][j].drawn_element[3].color = sf::Color::Red;
			*/
			//this part assighns a square a colour based apon its value so that a user may tell it apart
			if (map[i][j].gettype() == 0)
			{
				map[i][j].drawn_element[0].color = sf::Color::Red;
				map[i][j].drawn_element[1].color = sf::Color::Red;
				map[i][j].drawn_element[2].color = sf::Color::Red;
				map[i][j].drawn_element[3].color = sf::Color::Red;
			}
			else if (map[i][j].gettype() == 1)
			{
				map[i][j].drawn_element[0].color = sf::Color::Blue;
				map[i][j].drawn_element[1].color = sf::Color::Blue;
				map[i][j].drawn_element[2].color = sf::Color::Blue;
				map[i][j].drawn_element[3].color = sf::Color::Blue;
			}
			(*windowpointer).draw(*(map[i][j].passout_drawn_element()));
		}
	}
};