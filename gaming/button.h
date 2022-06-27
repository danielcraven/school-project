#pragma once
#include "constants.h"
#include "header.h"
#include "square.h"

class button
{
public:
	button(int place_number);
public:
	~button();
	void draw_self(sf::RenderWindow* window);
	std::string button_text;
	U_C uc;
	button_square_text square;
	int place_in_menu;
	//cheak issues
	void state_cords();
	void set_text(std::string pass_text,um::vector2dint* pass_pointer);
	um::vector2dint* mouse_cords = NULL;
	void poll_square_for_contact();
	bool pressed;
};