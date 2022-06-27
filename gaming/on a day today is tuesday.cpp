#include "bad.h"

void pri_menu::html(sf::RenderWindow* rodgerthestinker)
{
	std::cout << "deadf window first" << std::endl;
	winder = rodgerthestinker;
	mouse_rep.setRadius(5);
	std::cout << "deadf window" << std::endl;
}
void pri_menu::cheesr()//I belive this is the section that runs when the user opens a level and requres them click a circle that revolves aroudn the mouse inside of a square
{
	double cx = 0;
	double cy = 0;
	int frames = 0;
	double ypoint = 0;
	double xpoint = 0;
	while ((*winder).isOpen())
	{
		while ((*winder).pollEvent(event) || ((*winder).isOpen()) )
		{
			using namespace std;
			frames++;
			(*winder).clear(sf::Color::Black);
			sf::Vector2i mouse_position = sf::Mouse::getPosition(*winder);
			int mx = mouse_position.x;
			int my = mouse_position.y;
			if (true)
			{
				double val = 0.001;
				if (mx < cx)
				{
					cx = cx - val;
				}
				if (mx > cx)
				{
					cx = cx + val;
				}
				if (my < cy)
				{
					cy = cy - val;
				}
				if (my > cy)
				{
					cy = cy + val;
				}
			}
			// need to get pos;
			if (frames >= 360)
			{
				frames = 0;
			}
			int i = frames;
			double pi = 3.14159265358979323846;
			int cord[2] = { mx,my };
			int cord2[2] = { cord[0],cord[1] - 25 };
			xpoint = cos(i * (pi / 180)) * (cord2[0] - cord[0]) - sin(i * (pi / 180)) * (cord2[1] - cord[1]) + cord[0];
			ypoint = sin(i * (pi / 180)) * (cord2[0] - cord[0]) + cos(i * (pi / 180)) * (cord2[1] - cord[1]) + cord[1];
			cout << xpoint << std::endl;
			cout << ypoint << std::endl;
			mouse_rep.setPosition(xpoint, ypoint);
			box.setPosition(sf::Vector2f(100, 100));
			box.setSize(sf::Vector2f(100, 100));
			box.setFillColor(sf::Color::Blue);
			// actaual sech rec
			
			if ((xpoint >= 100 && xpoint <= 200) && (ypoint >= 100 && ypoint <= 200))
			{
				box.setFillColor(sf::Color::Red);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					(*winder).close();
				}
			}
			(*winder).draw(mouse_rep);
			(*winder).draw(box);
			(*winder).display();
			//this cheak rec
			
		}
	}
}
