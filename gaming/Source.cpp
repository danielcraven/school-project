#include "Header.h"
#include "Header1.h"
//#include "amogus.cpp"
// bad messy code I will admit
// can confirm file send
//file send 2

class calculations_cord
{
public:
	bool boxcol(int x, int y, int x1, int y1)// I belive this section cheaks to see if 2 square intersect
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
	bool lincol(int px, int py, int prex, int prey, int sx, int sy)//this section was inteded to cheak if 2 lines inersected though it did not work and has to be done via a working method
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
	//this function is over ridden in this sub class this is an example of polymorthism
	void lincol()
	{
		std::cout << "bad" << std::endl;
	};
	//needs actual code here
};

#include "header.h"
class calculations_cord;
class calc2;
class pstat
{
public://this classs controlls the player charicter
	calculations_cord cheese;
	calc2 cheese2;
	// pos
	bool* lkh;//this section defines what skills the player possesses
	int px = 0;//this and the next line define the charicter position
	int py = 0;
	int prex = 0;//this section and the next line define the charicter previus position
	int prey = 0;
	//mom
	double mx = 0; //this and the next line define the players momentom
	int my = 0;
	int jumpsleft;//these 2 defines weather or not the player can jump and how much
	bool canjump;
	int health;//dictates the polayers health and armor affect the gealth bar and armor bar that show on a differant window
	int armor;
	bool right;//is used to controll weather the player moves right as it is in that direction that move advanced movement is implemented
	// dmov
	int dmov()//move left
	{
		mx = mx + 1;
		//std::cout << "dmov" << std::endl;
		return 0;
	}
	int amov() //move right though this function I do not belive is still used
	{
		mx = mx - 1;
		//std::cout << "amov" << std::endl;
		return 0;
	}
	int jpmov() //allows jumping
	{
		if (*lkh)// if double jump allowed
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
		}
		else // no double jump
		{
			std::cout << "this one";
			if ((jumpsleft > 0))
			{
				jumpsleft = 0;
				if (my < 0)
				{
					my = 0;
				}
				my = my + 15;
				//std::cout << "jpmov" << std::endl;
			}
		}
		return 0;
	}
	void grav(int map[16][20])//this applies gravity and also makes sure that player does not fall through map
		//needs to have map array passed through so that it knows where the terrain is
	{
		if (right == true)// do this if player is moving right
		{
			mx = mx - 1;
		}
		if (mx < 0)// applies drag when moving in right direction when right = true drag and movement values reach an equalibriam and charicter keeps constant speed
		{
			double draga = mx / 6;
			mx = mx - draga;
			std::cout << "mem" << draga << std::endl;
		}
		bool aplid = 0;
		//std::cout << "called" << std::endl;
		//this moves through the map to get the cordinates of each square
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
					if (aplid == 0 &&/* px >= ix && px <= ix + 50 && py >= iy + 0 && py < iy + 50 */ cheese.boxcol(px, py, ix, iy))//does this if there is a collision and there has not being an intersection before
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
				if (map[ii][i] == 2)//special section that runs if it on a section that damages the player
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
	int col()//cancells out most velocity and appies a downwards force
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
	pstat(bool* passer) // sets the value of armor and health the bool ensures that it is inline with the player selected skills
	{
		if ((*(passer+1)) == true)
		{
			health = 360;
		}
		else 
		{
			health = 180;
		}
		if ((*(passer+2)))
		{
			armor = 180;
		}
		else
		{
			armor = (180 / 2);
		}
		right = false;
	}
};

class map
{
public:
	int mapmem[16][20] = { {0} };
	map(int level_to_load)//loads a map fome file ensures it is of the correct level in a smillar war it ensuires it saves to thje same level
	{
		std::string exitfile_name = "assets/level ";
		{
			std::stringstream int_to_string;
			std::string addit;
			int_to_string << level_to_load;
			int_to_string >> addit;
			exitfile_name = exitfile_name + addit + ".txt";
		}

		std::cout << "map started " << std::endl;
		std::ifstream mapread(exitfile_name);
		std::string mapline;
		int counter = 0;
		while (std::getline(mapread, mapline))//reads through the text line by line and assighns the proper value to the array
		{
			int len = mapline.length();
			for (int ii = 0; ii < len; ii++)
			{
				if (mapline[ii] == '1')
				{
					mapmem[counter][ii] = 1;
				}
				else if (mapline[ii] == '2')
				{
					mapmem[counter][ii] = 2;
				}
			}
			counter++;
		}
		for (int ii = 0; ii < 16; ii++)//this does y
		{
			//std::cout << std::endl;
			for (int i = 0; i < 20; i++)//this does x
			{
				//std::cout << mapmem[ii][i];
			}
		}
	}
	void drawer(sf::RenderWindow& wind2)
	{
		sf::RectangleShape dr2(sf::Vector2f(50, 50));
		sf::RectangleShape dr3(sf::Vector2f(50, 50));
		//goes through each tile and draws it acording to its value
		for (int ii = 0; ii < 16; ii++)//this does y
		{
			for (int i = 0; i < 20; i++)//this does x
			{
				if (mapmem[ii][i] == 1)
				{
					dr2.setFillColor(sf::Color(0, 255, 0));
					dr2.setPosition(i * 50,750 - (ii * 50));
					wind2.draw(dr2);
					//std::cout << ii << "drawn" << i << std::endl;
				}
				if (mapmem[ii][i] == 2)
				{
					dr3.setFillColor(sf::Color(255, 0, 0));
					dr3.setPosition(i * 50, 750 - (ii * 50));
					wind2.draw(dr3);
					//std::cout << ii << "drawn" << i << std::endl;
				}
			}
		}
	}
};
void soef(sf::Sound sounder)//runs in an other thread so that it does not either force the game to pause till the sound to finish or has the sound no longer plau when it leaves the scope in the code, though it could have potentality worked if it was passed a memoru adress rather than a value
{
	sounder.play();
	//std::cout << "play" << std::endl;
	Sleep(10000);
}
class pstat;
#include "bad.h"
int game(int level_to_load, bool* the)
{
	std::cout << "star" << std::endl;
	sf::RenderWindow* windowed = new sf::RenderWindow(sf::VideoMode(800, 600), "hhyt");//creasts window
	pri_menu menu;//section with square before game starts
	menu.html(windowed);
	menu.cheesr();
	std::cout << "star2" << std::endl;
	std::cout << "start confirm" << std::endl;
	map mapper(level_to_load);//loads the map
	srand(time(0));//part of the random number generator
	sf::SoundBuffer sound;
	sound.loadFromFile("assets/sound.wav");
	sf::Sound sounder;
	sounder.setBuffer(sound);
	int x = 1000;
	int y = 800;
	sf::RenderWindow wind(sf::VideoMode(x, y), "gaming");
	wind.setVerticalSyncEnabled(true);
	wind.setKeyRepeatEnabled(false);
	pstat num(the);
	num.lkh = the;
	int* dave = &num.health;
	int* craig = &num.armor;
	int* x2 = new int;
	*x2 = 400;
	int* y2 = new int;
	*y2 = 300;
	sf::RenderWindow* rob = new sf::RenderWindow(sf::VideoMode(*x2, *y2), "instrumentation");
	std::thread threadie(mega_mega_ultra_cheese, dave,craig,rob,x2,y2);
	threadie.detach();
	int frame = 0;
	int sec = 0;
	while (wind.isOpen())
	{
		frame++;
		if (frame = 60)
		{
			sec++;
			frame = 0;
			//std::cout << sec << std::endl;
		}
		sf::Event cheeser;
		while (wind.pollEvent(cheeser))//responds to playuer input
		{
			if (cheeser.type == sf::Event::KeyReleased)
			{
				if (cheeser.key.code == sf::Keyboard::D)
				{
					num.dmov();
				}
			}
			if (cheeser.type == sf::Event::KeyReleased)
			{
				if (cheeser.key.code == sf::Keyboard::A)
				{
					num.right = false;
					std::cout << "key rel" << std::endl;
				}
			}
			if (cheeser.type == sf::Event::KeyPressed)
			{
				if (cheeser.key.code == sf::Keyboard::A)
				{
					num.right = true;
					std::cout << "key pre" << std::endl;
				}
			}
			if (cheeser.type == sf::Event::KeyReleased)
			{
				if (cheeser.key.code == sf::Keyboard::Space)
				{
					std::cout << "space cmd" << std::endl;
					std::thread thread_obj(soef, sounder);
					thread_obj.detach();
					num.jpmov();
					//std::cout << "wcr" << std::endl;
				}
			}
			if (cheeser.type == sf::Event::KeyReleased)
			{
				if (cheeser.key.code == sf::Keyboard::S)
				{
					num.col();
					//epic_cheese::caller_cheak("sus amogus");
				}
			}
			if (cheeser.type == sf::Event::KeyPressed)
			{
				if (cheeser.key.code == sf::Keyboard::O)
				{
					num.health = num.health + 1;
				}
			}
			if (cheeser.type == sf::Event::KeyPressed)
			{
				if (cheeser.key.code == sf::Keyboard::L)
				{
					num.health = num.health - 1;
				}
			}
			if (cheeser.type == sf::Event::Closed)
			{
				(wind).close();
				(*rob).close();
			}
		}
		//stat cheak
			//std::cout << num.my << "//" << num.py << std::endl;
			//std::cout << num.mx << "//" << num.px << std::endl;
		//phsiscs
		//applies momentom to the plaer postion allowing them to move
		num.py = num.my + num.py;
		num.px = num.mx + num.px;
		num.grav(mapper.mapmem);
		//restores armor section below
		if ((sec%500) == 0)
		{
			if ((*(num.lkh+2)))
			{
				num.armor = 180;
			}
			else
			{
				num.armor = (180 / 2);
			}
		}
		/*if (!(num.px == num.prex))
		{
			std::cout << num.px << "cheese" << num.prex << std::endl;
		}*/
		//records location of previus position of plauer
		num.prex = num.px;
		num.prey = num.py;
		//end physicsc
		//section below draws all elements
		wind.clear(sf::Color::Black);
		mapper.drawer(wind);
		sf::RectangleShape dr(sf::Vector2f(50, 50));
		//random number gen
		//srand(time(0));
		//random number gen end
		dr.setFillColor(sf::Color((rand() % 255), (rand() % 255), (rand() % 255)));
		dr.setPosition(num.px,750-num.py);
		wind.draw(dr);
		wind.display();
		//std::cout << num.right << std::endl;
	}
	return 0;
}
