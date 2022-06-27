#include "header.h"
class calculations_cord;
class calc2;
class pstat
{
public:
	calculations_cord cheese;
	calc2 cheese2;
	// pos
	int px = 0;
	int py = 0;
	int prex = 0;
	int prey = 0;
	//mom
	int mx = 0;
	int my = 0;
	int jumpsleft;
	bool canjump;
	int health;
	int armor;
	bool right;
	// dmov
	int dmov()
	{
		mx = mx + 1;
		//std::cout << "dmov" << std::endl;
		return 0;
	}
	int amov()
	{
		mx = mx - 1;
		//std::cout << "amov" << std::endl;
		return 0;
	}
	int jpmov()
	{
		//std::cout << jumpsleft << "jump" << canjump << std::endl;
		if (canjump == 1)
		{
			canjump = 0;
			if (my < 0)
			{
				my = 0;
			}
			my = my + 15;
			//std::cout << "jpmov" << std::endl;
		}
		else if ((jumpsleft > 0))
		{
			jumpsleft--;
			if (my < 0)
			{
				my = 0;
			}
			my = my + 15;
			//std::cout << "jpmov" << std::endl;
		}
		return 0;
	}
	void grav(int map[16][20])
	{
		if (right == true)
		{
			mx = mx - 1;
		}
		bool aplid = 0;
		//std::cout << "called" << std::endl;
		for (int ii = 0; ii < 16; ii++)//this does y
		{
			for (int i = 0; i < 20; i++)//this does x
			{
				if (map[ii][i] == 1)
				{
					int iy = ii * 50;
					int ix = i * 50;
					//std::cout << std::endl;
					if (cheese.lincol(px, py, prex, prey, ix, iy))
					{
						//std::cout << "cheese" << std::endl;
					}
					if (aplid == 0 &&/* px >= ix && px <= ix + 50 && py >= iy + 0 && py < iy + 50 */ cheese.boxcol(px, py, ix, iy))
					{
						aplid = 1;
						//std::cout << "over" << std::endl;
						if (py <= iy + 50)
						{
							py = iy + 50;
							my = 0;
							jumpsleft = 1;
							canjump = 1;
						}
						else if (py > iy + 50)
						{
							my = my - 1;
							canjump = 0;
						}
					}
				}
				if (map[ii][i] == 2)
				{
					int iy = ii * 50;
					int ix = i * 50;
					if (aplid == 0 &&/* px >= ix && px <= ix + 50 && py >= iy + 0 && py < iy + 50 */ (cheese).boxcol(px, py, ix, iy))
					{
						aplid = 1;
						if (armor <= 0)
						{
							health = health - 1;
						}
						else
						{
							armor = armor - 1;
						}
						//std::cout << "over" << std::endl;
						if (py <= iy + 50)
						{
							py = iy + 50;
							my = 0;
							jumpsleft = 1;
							canjump = 1;
						}
						else if (py > iy + 50)
						{
							my = my - 1;
							canjump = 0;
						}
					}
				}
			}
		}
		if (aplid == 0)
		{
			//std::cout << "gro" << std::endl;
			if (py <= 0)
			{
				my = 0;
				py = 0;
				jumpsleft = 1;
				canjump = 1;
			}
			else if (py > 0)
			{
				my = my - 1;
			}
		}
	};
	int col()
	{
		{
			mx = mx / 5;
			mx = mx * -1;
			my = my / 5;
			my = my * -1;
			my = my - 20;
		}
		return 0;
	}
	pstat()
	{
		health = 360;
		armor = 180;
		right = false;
	}
};

namespace epic_cheese
{
	void caller_cheak(std::string int_put)
	{
		std::cout << int_put << std::endl;
	}
}
class calculations_cord
{
public:
	bool boxcol(int x, int y, int x1, int y1)
	{
		if (x < x1 + 50 && x1 < x + 50 && y < y1 + 50 && y1 < y + 50)// checks for collision while any one statement will be true all the time when they are both true then there is an intersection
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	bool lincol(int px, int py, int prex, int prey, int sx, int sy)
	{
		if (!(px == prex || py == prey))
		{
			double x1 = px - prex;
			double y1 = py - prey;
			double sy1 = sy - (sy + 50);
			double sx1 = sx - (sx);
			double fin = (x1 * sy1) - (y1 * sx1);
			if (fin == 0)
			{
				return TRUE;
			}
			return FALSE;
		}
	}
};
class calc2 : public calculations_cord
{
public:
	//over ridden function
	void lincol()
	{
		std::cout << "bad" << std::endl;
	};
	//needs actual code here
};