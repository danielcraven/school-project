#pragma once
#include "menu.h";
#include "Header.h";
#include "constants.h";

class menu_manager
{
	public:
	sf::RenderWindow* menu_manager_window_pointer;
	int* menu_pointer = NULL;
	main_menu main_menu_instance;
	level_menu level_menu_instance;
	skills_menu skills_menu_instance;
	settings_menu settings_menu_instance;
	quit_menu quit_menu_instance;
	void draw_relevent_menu();
	void inisialise_menus(bool * skills_available);
	void pass_pointer(sf::RenderWindow* pass_pointer);
	um::vector2dint* mouse_cords;
	void set_mouse_cords();
	void poll_all_menus_for_contact();
	~menu_manager();
	void set_value_to_menu_pointer(int dave);
	int get_value_to_menu_pointer();
};