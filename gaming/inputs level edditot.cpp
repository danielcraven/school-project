#include "inputs level edditor.h"

level_edditor_inputs::level_edditor_inputs(sf::RenderWindow* pass_window)
{
	window_pointer = pass_window;//this passes a pointer to the inside of the class so that the menu is not copyed
}
void level_edditor_inputs::mouse_gather()
{
	//the pirose of this section is to get both the mouse cordinates and weather it has clicked in this specific frame
	sf::Vector2i localpos = sf::Mouse::getPosition(*window_pointer);
	mouse_cords.setx(localpos.x);
	mouse_cords.sety(localpos.y);
	sf::Event event;
	bool timefix = false; //these 2 values ensure that it only registers a click once
	bool timefix2 = false;
	while ((*window_pointer).pollEvent(event))
	{
		timefix = true;
		timefix2 = true;
		if (event.type == sf::Event::MouseButtonReleased)
		{
			
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				(mouse_cords).set_correct(true);
			}
			else
			{
				(mouse_cords).set_correct(false);
			}
			
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				(mouse_cords).set_correct2(true);
			}
			else
			{
				(mouse_cords).set_correct2(false);
			}

		}
		else
		{
			(mouse_cords).set_correct(false); 
			(mouse_cords).set_correct2(false);
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				z = true;
			}
			else
			{
				z = false;
			}
		}
		else
		{
			z = false;
		}
	}
	//the section below means that if the mouse has being pressed previusly it will not be pressed again this is important so that the user does not accidently click through multiple menus with a single press of the mouse button
	if ((timefix == false))
	{
		(mouse_cords).set_correct(false);
		(mouse_cords).set_correct2(false);
	}
	if ((timefix2 == false))
	{
		z = false;
	}
}