#include "constants.h"
#include "menu.h"
#include "button.h"
#include "square.h"
button::button(int place_number)//this interger lets the button know where it needs to be
{
	//set vales and create shape memory
	place_in_menu = place_number;
	uc.setval();
	square.set_points_for_button(place_number, uc);  //the button is assighned its cordinates
	square.set_text(button_text,mouse_cords);//the text values that are kept in the button are given to the square
};
button::~button()
{
	//delete button_shape;
	//std::cout << "button delete" << std::endl;
}
void button::draw_self(sf::RenderWindow* window)
{
	square.update_drawn_element();//this ensures that infomation about the button is assighned to the part in sfml that allows it to be drawn to the screen
	//need to draww both elements or the button will be incomplete
	(*window).draw(*square.passout_drawn_element());
	(*window).draw(*square.passout_text_drawn_element());
}
void button::state_cords()
{
	square.print_cords();
}
void button::set_text(std::string pass_text, um::vector2dint* pass_pointer)//this part takes the text from the menu for the button to display, it also gives the menu cordinates in a pointer so it does not have to be updated
{
	button_text = pass_text;
	//std::cout << mouse_cords << std::endl << "as said before and I say again" << pass_pointer;
	mouse_cords = pass_pointer;
	square.set_text(button_text,mouse_cords);
	square.attach_text();
};
void button::poll_square_for_contact()//this tells the square to cheak if it has being touched
{
	//std::cout << std::endl << (mouse_cords) << "this is set in stone" << std::endl;
	square.poll_square_for_contact();
	pressed = square.pressed;//this moves the infomation back outwards so it can be processed in the menmu
	//std::cout << pressed << "you are cringew" << std::endl;
}