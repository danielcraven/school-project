#include "menu_manager.h"
#include "header.h"
#include "menu.h"
void menu_manager::draw_relevent_menu() //this section draws a menu dependsing and what menu the user is foucsed one
{
	(*menu_manager_window_pointer).clear(sf::Color::Black);
	switch(*menu_pointer)
	{
		case 0:
			main_menu_instance.draw_menu_features();
			break;
		case 1:
			level_menu_instance.draw_menu_features();
			break;
		case 2:
			skills_menu_instance.draw_menu_features();
			break;
		case 3:
			settings_menu_instance.draw_menu_features();
			break;
		case 4:
			quit_menu_instance.draw_menu_features();
			break;
	}
	(*menu_manager_window_pointer).display();
}
void menu_manager::inisialise_menus(bool* skills_available) // this section passes a menu nessesary memory addresses ,instructs them to correct certain values, and then instructs them to create an dynamic array of buttons
{
	//std::cout << "init" << std::endl;
	//std::cout << mouse_cords << std::endl;

	main_menu_instance.window_pass(menu_manager_window_pointer,mouse_cords,menu_pointer);
	main_menu_instance.set_value_of_poly();
	main_menu_instance.create_buttons();
	//std::cout << main_menu_instance.number_of_buttons << std::endl;
	level_menu_instance.window_pass(menu_manager_window_pointer, mouse_cords, menu_pointer);
	level_menu_instance.set_value_of_poly();
	level_menu_instance.create_buttons();
	skills_menu_instance.window_pass(menu_manager_window_pointer, mouse_cords, menu_pointer);
	skills_menu_instance.set_value_of_poly(skills_available);
	skills_menu_instance.create_buttons();
	settings_menu_instance.window_pass(menu_manager_window_pointer, mouse_cords, menu_pointer);
	settings_menu_instance.set_value_of_poly();
	settings_menu_instance.create_buttons();
	quit_menu_instance.window_pass(menu_manager_window_pointer, mouse_cords, menu_pointer);
	quit_menu_instance.set_value_of_poly();
	quit_menu_instance.create_buttons();
	//std::cout << "enit" << std::endl;
}
void menu_manager::pass_pointer(sf::RenderWindow* pass_pointer) //this section allows a memory address to be given to the window manager, it also assigngs some needed variables/ classes a memory adress
{
	//std::cout << "pass pointer" << std::endl;
	menu_manager_window_pointer = pass_pointer;
	mouse_cords = new um::vector2dint;
	menu_pointer = new int;
}
void menu_manager::set_mouse_cords()//the pirose of this section is to get both the mouse cordinates and weather it has clicked in this specific frame
{
	//sf::Event mouse_cords_get;
	//while ( (*menu_manager_window_pointer).waitEvent(mouse_cords_get) )
	//{
		//std::cout << "in the end" << std::endl;
	sf::Vector2i localpos = sf::Mouse::getPosition(*(menu_manager_window_pointer));
	//std::cout << localpos.x << std::endl << localpos.y << std::endl;
	//std::cout << mouse_cords;
	//the pirose of this section is to get both the mouse cordinates and weather it has clicked in this specific frame
	(*mouse_cords).setx(localpos.x);
	(*mouse_cords).sety(localpos.y);
	sf::Event event;
	bool timefix = false;//this value ensure that it only registers a click once
	while ((*menu_manager_window_pointer).pollEvent(event))
	{
		timefix = true;
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				(*mouse_cords).set_correct(true);
				//std::cout << "set true" << std::endl;
			}
			else
			{
				(*mouse_cords).set_correct(false);
				//std::cout << "set false" << std::endl;
			}
		}
		else
		{
			(*mouse_cords).set_correct(false);
			//std::cout << "set false but the bad way" << std::endl;
		}
		//std::cout << "end of seg" << std::endl;
	}

	
	if ((timefix == false))//the section below means that if the mouse has being pressed previusly it will not be pressed again this is important so that the user does not accidently click through multiple menus with a single press of the mouse button
	{
		(*mouse_cords).set_correct(false);
		//std::cout << "timefix" << std::endl;
	}
	//std::cout << (*mouse_cords).get_correct() << std::endl;
}
void menu_manager::poll_all_menus_for_contact()//this section ensurs only the active menu is cheaked to see if it it being pressed, not only does this save on processing, but also due to the way it has being coded without this the user would click on multiple buttons from differant menus
{
	switch (*menu_pointer)
	{
	case 0:
		main_menu_instance.poll_square_for_contact();
		break;
	case 1:
		level_menu_instance.poll_square_for_contact();
		break;
	case 2:
		skills_menu_instance.poll_square_for_contact();
		break;
	case 3:
		settings_menu_instance.poll_square_for_contact();
		break;
	case 4:
		quit_menu_instance.poll_square_for_contact();
		break;
	}
}
menu_manager::~menu_manager()//this saves memory when it is no longer nessesary though this is ultimeally pointless as menu mangager will only be deleted when the program closes so it does not truly matter
{
	delete mouse_cords;
}

void menu_manager::set_value_to_menu_pointer(int dave) //this sets a value for the menu pointer
{
	(*menu_pointer) = dave;
}
int menu_manager::get_value_to_menu_pointer()// this extracts a value for the menu pointer
{
	return (*menu_pointer);
}
