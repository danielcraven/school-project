#include "header.h"
#include "map(level edditor).h"
#include "inputs level edditor.h"
#include "stack.h"

void level_edditor_main(sf::RenderWindow* pass_pointer,int file_to_save)// funmction takes a pointer to the window so that it can draw to it, it also takes a number so it know which file to save to
{
	(*pass_pointer).clear(sf::Color::Black);
	U_C uc;
	uc.setval();
	map_level_edditor mapp;
	mapp.init_map();
	level_edditor_inputs inputs(pass_pointer);
	stack_change stacks;
	while (true)
	{
		inputs.mouse_gather();

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				mapp.map[i][j].testforpress(&inputs.mouse_cords, 1);
				if (mapp.map[i][j].pressed == true)
				{
					//this is not ideal and only leaves 2 options it would be better if it was split in to segmets and thus I could test if there was an intersection and get the previus result rather than just swapping and thus only being able to have 2
					if (inputs.mouse_cords.get_correct())
					{
						stacks.stack_push(i, j, 0);//pushes a change made to the stack
					}
					if (inputs.mouse_cords.get_correct2())
					{
						stacks.stack_push(i, j, 1);
					}
					stacks.dump_all();//prints the stack was used in development
				}
			}
		}
		if (inputs.z == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) // this part of the code works when redoing
			{
				std::cout << "prl " << std::endl;
				int num = NULL;
				int x;
				int y;
				bool full = false;
				stacks.redo(num, x, y,full);//the values are passed out by reference then applied further down
				std::cout << num << std::endl << x << std::endl << y << std::endl;
				if (num == 0)
				{
					num = 1;
				}
				else if (num == 1)
				{
					num = 0;
				}
				std::cout << std::endl << num << std::endl << x << std::endl << y << std::endl;
				if (full == true)
				{
					mapp.map[x][y].type = num;
				}
			}
			else //this part of the code runs when undoing
			{
				std::cout << "hjk " << std::endl;
				int num = NULL;
				int x;
				int y;
				bool full = false;
				stacks.stack_pop(num, x, y,full);
				if (full == true)
				{
					mapp.map[x][y].type = num;
					std::cout << "de 1" << std::endl;
				}
			}
		}

		mapp.print_map(pass_pointer);
		(*pass_pointer).display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			std::cout << "funk not yet avl " << file_to_save << std::endl;
			break;//exits the while true loop and allows the files to be saved
		}
	}
	std::string exitfile_name = "assets/level ";//this is the string which gets the last value added to it so it can then open the aproptiet file
	{
		std::stringstream int_to_string;
		std::string addit;
		int_to_string << file_to_save;
		int_to_string >> addit;
		exitfile_name = exitfile_name + addit + ".txt";
		// this section converts a int to a tring then adds it to the end of the file name
	}
	std::cout << exitfile_name << std::endl;

	std::ofstream myfile(exitfile_name);
	//this section uses for loops to add the array into a text docuemnt in the correct order, it will then read the the docuemnt in the playable part of the game
	if (myfile.is_open())
	{
		inputs.mouse_gather();
		for (int j = 0; j < 16; j++)
		{
			for (int i = 0; i < 20; i++)
			{
				myfile << mapp.map[i][j].gettype();
			}
			myfile << std::endl;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
};
