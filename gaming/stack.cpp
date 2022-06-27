#include <vector>
#include "stack.h"
change::change(int num,int x,int y)
{
	set = num;
	cords[0] = x;
	cords[1] = y;
}
void stack_change::stack_push(int x, int y, int num)
{
	std::cout << "de 3" << std::endl;
	// it should be noted that the recent changes while they save memory they also make the program run slower as the program will need to request more memory

	//std::cout << std::endl;
	//std::cout << "onac";
	int length = change_list.size();
	if (length > stack_pointer)
	{
		
		//first part this deletes prior from re_do

		std::cout << "s// " << change_list.size() << std::endl;

		std::vector<change>::iterator it1;
		it1 = change_list.begin() + stack_pointer;

		std::vector<change>::iterator it2;
		it2 = change_list.end() - 1;

		std::cout << (*it1).cords[0] << (*it1).cords[1] << std::endl;
		std::cout << (*it2).cords[0] << (*it2).cords[1] << std::endl;

		change_list.erase(it1,it2);
		
		std::cout << "e// " << change_list.size() << std::endl;

		
		std::cout << "regstart " << change_list.size() << "cheese " << stack_pointer << std::endl;
		for (int i = 0; i < change_list.size(); i++)
		{
			std::cout << change_list[i].set << "- was previusly at -" << change_list[i].cords[0] << ":" << change_list[i].cords[1] << std::endl;
		}
		std::cout << "regend" << std::endl;
		

		//second part saves values to the stack after they were undone

		change_list[stack_pointer].set = num;
		change_list[stack_pointer].cords[0] = x;
		change_list[stack_pointer].cords[1] = y;
		stack_pointer++;
	}
	else//this part runs if the stack is not full and there is missing space, given the recently added scerion that delets prior records it is likley this section is not used
	{
		//std::cout << "2" << std::endl;
		change dave(num,x,y);
		change_list.push_back(dave);
		stack_pointer++;
	}
}

void stack_change::dump_all()//this section was orriginaly made to print out infomation during devlopment it has being commented out as it was no longer needed
{
	/*std::cout << "regstart " << change_list.size() << "cheese " << stack_pointer << std::endl;
	for (int i = 0; i < change_list.size(); i++)
	{
		std::cout << change_list[i].set << "- was previusly at -" << change_list[i].cords[0] << ":" << change_list[i].cords[1] << std::endl;
	}
	std::cout << "regend" << std::endl;
	*/
}
void stack_change::stack_pop(int &outnum,int &outx ,int &outy,bool& full)
{
	if (stack_pointer > 0)//the stack is being popped so infomation must be returned to outside the stack this is done via referance
	{
		stack_pointer--;
		outnum = change_list[stack_pointer].set;
		outx = change_list[stack_pointer].cords[0];
		outy = change_list[stack_pointer].cords[1];
		std::cout << stack_pointer << std::endl;
		//std::cout << change_list[stack_pointer].set << std::endl << change_list[stack_pointer].cords[0] << std::endl << change_list[stack_pointer].cords[1] << std::endl;
		std::cout << outnum << std::endl << outx << std::endl << outy << std::endl;


		std::cout << "regstart " << change_list.size() << "cheese " << stack_pointer << std::endl;
		for (int i = 0; i < change_list.size(); i++)
		{
			std::cout << change_list[i].set << "- was previusly at -" << change_list[i].cords[0] << ":" << change_list[i].cords[1] << std::endl;
		}
		std::cout << "regend" << std::endl;

		full = true;
	}
	else//this means the stack is empty
	{
		std::cout << "no undo left" << std::endl;
	}
	
}
void stack_change::redo(int& outnum, int& outx, int& outy,bool& full)
{
	if (stack_pointer < change_list.size() )//the stack has space to move farwardds this is differant from pop ing as it is being moved back to spaces it has previusly ocupied
	{
		stack_pointer++;
		outnum = change_list[stack_pointer -1 ].set;
		outx = change_list[stack_pointer -1].cords[0];
		outy = change_list[stack_pointer-1].cords[1];
		std::cout << stack_pointer << std::endl;
		//std::cout << change_list[stack_pointer].set << std::endl << change_list[stack_pointer].cords[0] << std::endl << change_list[stack_pointer].cords[1] << std::endl;
		std::cout << outnum << std::endl << outx << std::endl << outy << std::endl;


		std::cout << "regstart " << change_list.size() << "cheese " << stack_pointer << std::endl;
		for (int i = 0; i < change_list.size(); i++)
		{
			std::cout << change_list[i].set << "- was previusly at -" << change_list[i].cords[0] << ":" << change_list[i].cords[1] << std::endl;
		}
		std::cout << "regend" << std::endl;

		full = true;
	}
	else//the pointer is at the edge of the list if it goes any further it will cause a memory access error
	{
		std::cout << "you are at the edge" << std::endl;
	}

}
//this is a comment