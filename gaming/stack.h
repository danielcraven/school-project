#include "header.h"

class change
{
public:
	int cords[2];
	int set;
	change(int x, int y, int num);
};

class stack_change
{	
private:
	std::vector<change> change_list;
	int stack_pointer = 0;
public:
	void stack_push(int x, int y, int num);
	void dump_all();
	void stack_pop(int & outnum, int & outx, int & outy, bool & full);
	void redo(int & outnum, int & outx, int & outy, bool & full);
};