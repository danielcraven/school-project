#pragma once
#include "header.h"
#include "button.h"
#include "menu.h"

class menu
{
// retating to the holding and passing of windows
public:
	U_C uc;
	sf::RenderWindow* main_menu_window_pointer;
// done due to buttons
	int number_of_buttons/* = 4*/;
	std::vector<std::string> list_of_text/* = {"one","two","three","four"}*/;
//	void set_value_of_poly();
public:
	void window_pass(sf::RenderWindow* pass_pointer, um::vector2dint* pass_pointer_cord, int* pass_pointer_menu_screen);
// buttons
	std::vector<button> button_list;
	void create_buttons();
	void draw_menu_features();
// mem issues
	~menu();
	void state_buttons();
	sf::Texture menu_texture;
	sf::Sprite menu_prite;
	//this is so I commit image
	um::vector2dint* mouse_cords;
	void poll_square_for_contact();
	int* menu_manager_pointer;
};

class main_menu : public menu
{
public:
	int true_number_of_buttons = 4;
	std::vector<std::string> true_list_of_text = {"levels","skills","level edditor","quit"};
	void set_value_of_poly();
	void poll_square_for_contact();
};
class level_menu : public menu
{
public:
	int true_number_of_buttons = 4;
	std::vector<std::string> true_list_of_text = { "play level 1","play level 2","play level 3","return" };
	void set_value_of_poly();
	void poll_square_for_contact();
};
class skills_menu : public menu
{
public:
	int true_number_of_buttons = 4;
	std::vector<std::string> true_list_of_text = { "double jump","extra armor","extra health","return" };
	void set_value_of_poly(bool* skills_available);
	void poll_square_for_contact();
	bool* skills_sel;
};
class settings_menu : public menu
{
public:
	int true_number_of_buttons = 4;
	std::vector<std::string> true_list_of_text = { "write level 1","write level 2","write level 3","return" };
	void window_pass(sf::RenderWindow * pass_pointer, um::vector2dint * pass_pointer_cord, int * pass_pointer_menu_screen);
	void set_value_of_poly();
	void poll_square_for_contact();
};
class quit_menu : public menu
{
public:
	int true_number_of_buttons = 2;
	std::vector<std::string> true_list_of_text = { "go back","go honme" };
	void window_pass(sf::RenderWindow * pass_pointer, um::vector2dint * pass_pointer_cord, int * pass_pointer_menu_screen);
	void set_value_of_poly();
	void poll_square_for_contact();
};