#include "menu.h"

void menu::window_pass(sf::RenderWindow* pass_pointer,um::vector2dint* pass_pointer_cord,int* pass_pointer_menu_screen)//this section passes a pointer into a menu and also loads a background iamge
{
	main_menu_window_pointer = pass_pointer;
	mouse_cords = pass_pointer_cord;
	menu_manager_pointer = pass_pointer_menu_screen;

	uc.setval();
	//std::cout << "window pass" << std::endl;
	
	menu_texture.loadFromFile("assets/game picture.png");
	menu_prite.setTexture(menu_texture);
	menu_prite.setTextureRect(sf::IntRect(0,0,uc.menu_resolution.getx(),uc.menu_resolution.gety()));
	
}
void quit_menu::window_pass(sf::RenderWindow* pass_pointer, um::vector2dint* pass_pointer_cord, int* pass_pointer_menu_screen) //this section loads a differant picture
{
	main_menu_window_pointer = pass_pointer;
	mouse_cords = pass_pointer_cord;
	menu_manager_pointer = pass_pointer_menu_screen;

	uc.setval();
	//std::cout << "window pass" << std::endl;

	menu_texture.loadFromFile("assets/game picture 2.png");
	menu_prite.setTexture(menu_texture);
	menu_prite.setTextureRect(sf::IntRect(0, 0, uc.menu_resolution.getx(), uc.menu_resolution.gety()));

}
void settings_menu::window_pass(sf::RenderWindow* pass_pointer, um::vector2dint* pass_pointer_cord, int* pass_pointer_menu_screen) // this section also loads a differant picture
{
	main_menu_window_pointer = pass_pointer;
	mouse_cords = pass_pointer_cord;
	menu_manager_pointer = pass_pointer_menu_screen;

	uc.setval();
	//std::cout << "window pass" << std::endl;

	menu_texture.loadFromFile("assets/game picture 3.png");
	menu_prite.setTexture(menu_texture);
	menu_prite.setTextureRect(sf::IntRect(0, 0, uc.menu_resolution.getx(), uc.menu_resolution.gety()));

}
/*
void menu::clear_window()
{
	(*main_menu_window_pointer).clear(sf::Color::Black);
}
void menu::display_window()
{
	(*main_menu_window_pointer).display();
}
*/
void menu::create_buttons() //this section creates a list of buttons in the menu
{
	//std::cout << "create buttons" << std::endl;
	button_list.reserve(number_of_buttons);
	for (int i = 1; i <= number_of_buttons; i++)
	{
		//std::cout << std::endl << (mouse_cords) << "as said my cheese" << std::endl;
		(button_list).push_back(i);
		(button_list)[i - 1].set_text(list_of_text[i-1],mouse_cords);
	}
}

void menu::draw_menu_features() //this section goes through the list of buttons and has sfml draw them
{
	(*main_menu_window_pointer).draw(menu_prite);
	int length = number_of_buttons;
	for (int i = 1; i <= (length); i++)
	{
		(button_list)[i-1].draw_self(main_menu_window_pointer);
	}
}

menu::~menu() //distructor unused
{

}
void menu::state_buttons() //used in development prints cordinates of buttons to ensure correct posittioning
{
	int size = button_list.size();
	//std::cout << number_of_buttons << std::endl;
	//std::cout << size << std::endl;
	for (int i = 0; i < size; i++)
	{
		(button_list)[i].state_cords();
	}
}
//void menu::set_value_of_poly()
//{
	//function to be over ridden in sub classes
	//std::cout << "this is to be set as gone" << std::endl;
//}

//this is most inideal and I did not want to do this

void main_menu::set_value_of_poly() //this overrides some values in the class so that differant menus can exist
{
	{
		//std::cout << "rat" << std::endl;
		number_of_buttons = true_number_of_buttons;
		(list_of_text).reserve(number_of_buttons);
		list_of_text = true_list_of_text;
		//std::cout << "rat" << std::endl;
	}
}
void level_menu::set_value_of_poly()//does the same as previsu this must be done muiltiple times to override in differant menus
{
	{
		//std::cout << "rat" << std::endl;
		number_of_buttons = true_number_of_buttons;
		(list_of_text).reserve(number_of_buttons);
		list_of_text = true_list_of_text;
		//std::cout << "rat" << std::endl;
	}
}
void skills_menu::set_value_of_poly(bool* skills_available)//same as above exept this one needs to interact with the skills thus the skills available bool is involved
{
	{
		std::cout << "rat" << std::endl;
		number_of_buttons = true_number_of_buttons;
		(list_of_text).reserve(number_of_buttons);
		list_of_text = true_list_of_text;
		std::cout << "rat" << std::endl;
		skills_sel = skills_available;
		std::cout << *(skills_sel) << std::endl;
	}
}
void settings_menu::set_value_of_poly()//same as the one above the one above
{
	{
		//std::cout << "rat" << std::endl;
		number_of_buttons = true_number_of_buttons;
		(list_of_text).reserve(number_of_buttons);
		list_of_text = true_list_of_text;
		//std::cout << "rat" << std::endl;
	}
}
void quit_menu::set_value_of_poly() //same as one above
{
	{
		//std::cout << "rat" << std::endl;
		number_of_buttons = true_number_of_buttons;
		(list_of_text).reserve(number_of_buttons);
		list_of_text = true_list_of_text;
		//std::cout << "rat" << std::endl;
	}
}
void menu::poll_square_for_contact()// this tells the buttons to cheak if they have being pressed it then takes action on that by changing the menyu pointer to influence the game
{
	//std::cout << /*std::endl << (*mouse_cords).gety() <<*/ " indide menuy" << std::endl;
	for (int i = 0; i < number_of_buttons; i++)
	{
		button_list[i].poll_square_for_contact();
		if (button_list[i].pressed == true)
		{
			//std::cout << button_list[i].place_in_menu << "true" << number_of_buttons << std::endl;
			if (button_list[i].place_in_menu == number_of_buttons)
			{
				//std::cout << "set to 0" << std::endl;
				(*menu_manager_pointer) = 0;
			}
		}
	}
}
void main_menu::poll_square_for_contact() // same as above but slightly differant as it allows the user to switch menus
{
	//std::cout << std::endl << (*mouse_cords).gety() << " indide menuy" << std::endl;
	for (int i = 0; i < number_of_buttons; i++)
	{
		button_list[i].poll_square_for_contact();
		if (button_list[i].pressed == true)
		{
			(*menu_manager_pointer) = button_list[i].place_in_menu;
			if (button_list[i].place_in_menu == number_of_buttons)
			{
				//std::cout << "die" << std::endl;
			}
		}
	}
}
void settings_menu::poll_square_for_contact() // same as 2 above but allows the user to select a game level or go back
{
	//std::cout << std::endl << (*mouse_cords).gety() << " indide menuy" << std::endl;
	for (int i = 0; i < number_of_buttons; i++)
	{
		button_list[i].poll_square_for_contact();
		if (button_list[i].pressed == true)
		{
			//std::cout << button_list[i].place_in_menu << "true" << number_of_buttons << std::endl;
			if (button_list[i].place_in_menu == number_of_buttons)
			{
				//std::cout << "set to 0" << std::endl;
				(*menu_manager_pointer) = 0;
			}
			if (button_list[i].place_in_menu == 1)
			{
				//std::cout << "set to 47" << std::endl;
				(*menu_manager_pointer) = 47;
			}
			if (button_list[i].place_in_menu == 2)
			{
				//std::cout << "set to 47" << std::endl;
				(*menu_manager_pointer) = 48;
			}
			if (button_list[i].place_in_menu == 3)
			{
				//std::cout << "set to 47" << std::endl;
				(*menu_manager_pointer) = 49;
			}
		}
	}
}
void quit_menu::poll_square_for_contact() // same as 3 above but allows the user quit the game
{
	//std::cout << std::endl << (*mouse_cords).gety() << " indide menuy" << std::endl;
	for (int i = 0; i < number_of_buttons; i++)
	{
		button_list[i].poll_square_for_contact();
		if (button_list[i].pressed == true)
		{
			//std::cout << button_list[i].place_in_menu << "true" << number_of_buttons << std::endl;
			if (button_list[i].place_in_menu == number_of_buttons)
			{
				//std::cout << "set to 0" << std::endl;
				(*menu_manager_pointer) = 0;
			}
			if (button_list[i].place_in_menu == 1)
			{
				//std::cout << "set to 47" << std::endl;
				(*menu_manager_pointer) = 63;
			}
		}
	}
}
void level_menu::poll_square_for_contact()// same as 4 above but allows the user to select a level to edit
{
	//std::cout << /*std::endl << (*mouse_cords).gety() <<*/ " indide menuy" << std::endl;
	for (int i = 0; i < number_of_buttons; i++)
	{
		button_list[i].poll_square_for_contact();
		if (button_list[i].pressed == true)
		{
			//std::cout << button_list[i].place_in_menu << "true" << number_of_buttons << std::endl;
			if (button_list[i].place_in_menu == 1)
			{
				//std::cout << "set to 0" << std::endl;
				(*menu_manager_pointer) = 917;
			}
			if (button_list[i].place_in_menu == 2)
			{
				//std::cout << "set to 0" << std::endl;
				(*menu_manager_pointer) = 918;
			}
			if (button_list[i].place_in_menu == 3)
			{
				//std::cout << "set to 0" << std::endl;
				(*menu_manager_pointer) = 919;
			}
			if (button_list[i].place_in_menu == number_of_buttons)
			{
				//std::cout << "set to 0" << std::endl;
				(*menu_manager_pointer) = 0;
			}
		}
	}
}
void skills_menu::poll_square_for_contact() // same as 5 above but allows the user to select skills thus it must work a little differant and use its specialy given bool array rather than the standard method
{
	//std::cout << /*std::endl << (*mouse_cords).gety() <<*/ " indide menuy" << std::endl;
	for (int i = 0; i < number_of_buttons; i++)
	{
		button_list[i].poll_square_for_contact();
		if (button_list[i].pressed == true)
		{
			//std::cout << button_list[i].place_in_menu << "true" << number_of_buttons << std::endl;
			if (button_list[i].place_in_menu == 1)
			{
				//std::cout << "set to 0" << std::endl;
				// I belive for this section I may have been better making a function to call rather than copying and pasting code with was all most completly ideanticle with the excetption of one intergervalue incrementing a memory address
				if (*(skills_sel) == true)
				{
					(*(skills_sel) = false);
				}
				else if (*(skills_sel) == false)
				{
					(*(skills_sel) = true);
				}
				std::cout << skills_sel << skills_sel + 1 << skills_sel + 2 << std::endl;
				std::cout << (*(skills_sel)) << " " << (*(skills_sel + 1)) << " " << (*(skills_sel + 2)) << " " << std::endl;
			}
			if (button_list[i].place_in_menu == 2)
			{
				//std::cout << "set to 0" << std::endl;
				if (*(skills_sel+1) == true)
				{
					(*(skills_sel+1) = false);
				}
				else if (*(skills_sel+1) == false)
				{
					(*(skills_sel+1) = true);
				}
				std::cout << skills_sel << (skills_sel + 1) << (skills_sel + 2) << std::endl;
				std::cout << (*(skills_sel)) << " " << (*(skills_sel + 1)) << " " << (*(skills_sel + 2)) << " " << std::endl;
			}
			if (button_list[i].place_in_menu == 3)
			{
				//std::cout << "set to 0" << std::endl;
				if (*(skills_sel+2) == true)
				{
					(*(skills_sel+2) = false);
				}
				else if (*(skills_sel+2) == false)
				{
					(*(skills_sel+2) = true);
				}
				std::cout << skills_sel << skills_sel + 1 << skills_sel + 2 << std::endl;
				std::cout << (*(skills_sel)) << " " << (*(skills_sel + 1)) << " " << (*(skills_sel + 2)) << " " << std::endl;
			}
			if (button_list[i].place_in_menu == number_of_buttons)
			{
				//std::cout << "set to 0" << std::endl;
				(*menu_manager_pointer) = 0;
			}
		}
	}
}