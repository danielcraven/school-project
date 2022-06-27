#pragma once

#include "constants.h"

#include "header.h"

class square
{
public:
	square();
	um::vector2dint points [4];
	sf::VertexArray drawn_element;
	void update_drawn_element();
	sf::VertexArray* passout_drawn_element();
	~square();
	void print_cords();
};

class button_assinged_square : public square
{
public:
	void set_points_for_button(int button_number, U_C uc);
};

class button_square_text : public button_assinged_square
{
	public:
		std::string square_text;
		sf::Text square_text_drawn_element;
	public:
		void set_text(std::string pass_text, um::vector2dint* pass_pointer_mouse_cords);
		void attach_text();
		sf::Text* passout_text_drawn_element();
		U_C uc;
		um::vector2dint* mouse_cords;
		void poll_square_for_contact();
		bool pressed = false;
};

class level_modifercation_tile : public square
{
public:
	int type = 0;
public:
	void testforpress(um::vector2dint* mouse_cords, int type_set);
	int gettype();
	bool pressed;
};