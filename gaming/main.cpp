//hello this is a comment
#include "header.h"
#include "menu.h"
#include "constants.h"
#include "menu_manager.h"
//next set
#include "map(level edditor).h"
#include "main(level edditor).h"
//forward declareation of a function that is not included in the header files


int game(int level_to_load , bool* the);

int main()
{
	//this is the start of the code
	bool* skills = new bool[3];
	(*skills) = false;
	(*(skills+1)) = false;
	(*(skills+2)) = false;
	// these are being given a value to pervent issues with memory later in runtime
	std::cout << (*skills) << std::endl;
	U_C	uc;
	uc.setval();
	menu_manager menu;
	sf::RenderWindow* main_window =new sf::RenderWindow(sf::VideoMode(uc.menu_resolution.getx(),uc.menu_resolution.gety()), " ");
	std::cout << "start" << std::endl;
	menu.pass_pointer(main_window);//this passes a pointer for the window so elements in the memory manager can be drawn
	menu.inisialise_menus(skills);//this assighns values to the buttons so that calcuations can be done, the valuyes are assighned at run time so that they can be adjusted to the screen size unfortunaly the abblity to select screen size was not fully implermented
	menu.set_value_to_menu_pointer(0); //it is ideal this pointer is renamed perhapse to marker to avide confusion
	bool halt = true;
	while (halt == true) //this is used so that program can be ended rather properly rather than forcing the user to close it through other means or to simply crash the program
	{
		//std::cout << "start loop" << std::endl;
		menu.draw_relevent_menu();// this line draws the menu to the screen
		//std::cin >> menu.menu_pointer;
		menu.set_mouse_cords();// this line gets the cordinates of the mouse so that they can be used to test for clicking
		menu.poll_all_menus_for_contact();
		//this then makes the menu cheak when they have being pressed or in other words when both the mouse has being clicked and the mouses cordintates intersect a button
		menu.draw_relevent_menu();//this draws the menus a second time so that, I added a feature so the button disapears when clicked but if this line is not here then the game has moved to another button before the change can be drawn and shown to a user
		//std::cout << menu.get_value_to_menu_pointer() << std::endl;
		switch (menu.get_value_to_menu_pointer())//the menu pointer value is sometimes changed when a button is pressed sometimes this means that a now part of the program needs to be moved so we will move to another function that is the purpose of this function some buttons change the value to a pre selected random number which this switch case will then
		{
		case 47:// this case opens the level editor for level 1
			std::cout << "a test of skill" << std::endl;
			menu.set_value_to_menu_pointer(0);
			level_edditor_main(main_window,1);
			break;
		case 48:// this case opens the level editor for level 2
			std::cout << "a test of skill" << std::endl;
			menu.set_value_to_menu_pointer(0);
			level_edditor_main(main_window,2);
			break;
		case 49:// this case opens the level editor for level 3
			std::cout << "a test of skill" << std::endl;
			menu.set_value_to_menu_pointer(0);
			level_edditor_main(main_window,3);
			break;
		case 63://this closes the program
			std::cout << "you should" << std::endl;
			halt = false;
			break;
		case 917://this opens the playable part of the game at level 1
			std::cout << "you shouldn't" << std::endl;
			menu.set_value_to_menu_pointer(0);
			game(1,skills);
			break;
		case 918://this opens the playable part of the game at level 2
			std::cout << "you shouldn't" << std::endl;
			menu.set_value_to_menu_pointer(0);
			game(2,skills);
			break;
		case 919://this opens the playable part of the game at level 3
			std::cout << "you shouldn't" << std::endl;
			menu.set_value_to_menu_pointer(0);
			game(3,skills);
			break;
		}
	}
}