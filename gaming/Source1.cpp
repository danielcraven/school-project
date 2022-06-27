
#include "Header.h"
#include "Header1.h"
void gather(double* dave)
{
	std::cin >> *dave;
	std::cin >> *(dave + 1);
}
void cheak(double* dave)
{
	std::cout << *(dave) << std::endl;
	std::cout << *(dave + 1) << std::endl;
}

class line
{
public:
	double* point_1;
	double* point_2;
	double grad;
	double c;
	line()
	{
		point_1 = new double{ 2 };
		gather(point_1);
		cheak(point_1);
		point_2 = new double{ 2 };
		gather(point_2);
		cheak(point_2);
	}
	void getvalues_mid()
	{
		double cx = (point_1[0] - point_2[0]);
		double cy = (point_1[1] - point_2[1]);
		grad = ((point_1[0] - point_2[0]) / (point_1[1] - point_2[1]));
		grad = cy / cx;
		c = point_1[1] - (grad * point_1[0]);
		if (true)
		{
			using namespace std;
			cout << "this is gc:  " << grad << "//" << c << endl;
			//cout << point_1[0] << "//" << point_2[0] << "//" << (point_1[0] - point_2[0]) << endl;
			//cout << point_1[1] << "//" << point_2[1] << "//" << (point_1[1] - point_2[1]) << endl;
		}
	}
};
class purex
{
public:
	double gc1[2];
	double gc2[2];
	double ax;
	purex(line* set_state)
	{
		using namespace std;
		gc1[0] = (*set_state).grad;
		std::cout << (*set_state).grad << endl;
		gc1[1] = (*set_state).c;
		std::cout << (*set_state).c << endl;
		gc2[0] = (*(set_state + 1)).grad;
		std::cout << (*(set_state + 1)).grad << endl;
		gc2[1] = (*(set_state + 1)).c;
		std::cout << (*(set_state + 1)).c << endl;
	}
	double find_px()
	{
		using namespace std;
		double ag = gc1[0] - gc2[0];
		cout << ag << endl;
		double ac = gc2[1] - gc1[1];
		cout << ac << endl;
		ax = ac / ag;
		return ax;
	}
};
class check_range
{
public:
	double abx;
	double aby;
	double point_1[2];
	double point_2[2];
	double point_3[2];
	double point_4[2];
	check_range(double abxs, double abys, line* set_state)
	{
		abx = abxs;
		aby = abys;
		point_1[0] = set_state[0].point_1[0];
		point_1[1] = set_state[0].point_1[1];
		point_2[0] = set_state[0].point_2[0];
		point_2[1] = set_state[0].point_2[1];
		point_3[0] = set_state[1].point_1[0];
		point_3[1] = set_state[1].point_1[1];
		point_4[0] = set_state[1].point_2[0];
		point_4[1] = set_state[1].point_2[1];
	}
	bool comp()
	{
		//IMPORTANT ONE SHOULD NOTE THAT THIS DOES NOT HAVE PROPER PROTECTION AGAINST PARALELE LINES AND THE ONLY SAFE GUARD MEANS THE INFINETY THAT THE 0'S PRODUCE DOES NOT FIT IN WITH THE PREVIUS ENTERED POINTS MAKING IT INVALID WILL THIS BE SUFFICENT
		using namespace std;
		bool xval = 0;
		bool yval = 0;
		cout << point_1[0] << "<=" << abx << "<=" << point_2[0] << "||" << point_2[0] << "<=" << abx << "<=" << point_1[0] << endl;
		if ((point_1[0] <= abx && abx <= point_2[0]) || (point_2[0] <= abx && abx <= point_1[0]))
		{
			cout << "is true" << endl;
			cout << point_3[0] << "<=" << abx << "<=" << point_4[0] << "||" << point_4[0] << "<=" << abx << "<=" << point_3[0] << endl;
			if ((point_3[0] <= abx && abx <= point_4[0]) || (point_4[0] <= abx && abx <= point_3[0]))
			{
				cout << "is true" << endl;
				return 1;
			}
		}
		else
		{
			cout << "is untrue" << endl;
		}

		/*
		if (abx >= point_1[0] && abx <= point_2[0])
		{
			xval = 1;
			cout << "correct  ";
		}
		cout << abx << ">=" << point_1[0] << "and" << abx << "<=" << point_2[0] << endl;
		if (abx >= point_2[0] && abx <= point_1[0])
		{
			xval = 1;
			cout << "correct  ";
		}
		cout << abx << ">=" << point_2[0] << "and" << abx << "<=" << point_1[0] << endl;
		if (aby <= point_1[1] && aby >= point_2[1])
		{
			yval = 1;
			cout << "correct  ";
		}
		cout << aby << "<=" << point_1[1] << "and" << aby << ">=" << point_2[1] << endl;
		if (aby <= point_2[1] && aby >= point_1[1])
		{
			yval = 1;
			cout << "correct  ";
		}
		cout << aby << "<=" << point_2[1] << "and" << aby << ">=" << point_1[1] << endl;
		if (xval == 1 && yval == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
		*/
		//attempt at area does not work will retry

	}
};
class line_checker
{
public:
	line_checker()//this part was ment to cheak if lines intersect this attempt does infact work but was unable to be added to the code
	{
		line liner[2];
		liner[0].getvalues_mid();
		liner[1].getvalues_mid();
		line* cheese = &liner[0];
		purex xer(cheese);
		double abx = xer.find_px();
		double aby = (abx * liner[0].grad) + liner[0].c;
		std::cout << abx << "//" << aby << std::endl;
		check_range www(abx, aby, cheese);
		std::cout << www.comp() << std::endl << "exeption for sus number 128 " << std::endl;
	}
};
//second stage
void mega_mega_ultra_cheese(int* rodger,int* richard, sf::RenderWindow* dave,int* x2,int* y2)//this section draws the health bar and the armor bar to the screen
{
	// some elements are passed to this function these include the armor and health values as pointers so they can be modifed also a render window is added as well
	//the next 4 lines are not belived to serve a purpose
	int x = *x2;
	int y = *y2;
	delete x2;
	delete y2;
	(*dave).setVerticalSyncEnabled(true);
	(*dave).setKeyRepeatEnabled(true);
	//std::cout << "correct move" << std::endl;
	//while ((*dave).isOpen())
	while (true)
	{
	int cheese = *rodger;//this is to ensure that the value does not change as it is being drawn which could potentaly cause an issue given the game has this seciton in a second thread
	//std::cout << "about to attempt access" << std::endl;
	// circle code
	//std::cout << "cc1" << std::endl;
	double pi = 3.14159265358979323846;//pie is needed as this section uses circles
	//the next sections are preset values that can then be rotated with cos and sine
	int cord[2] = { x/2,y/2 };
	int cord2[2] = { cord[0],cord[1] - x/4 };
	double angle = 1 * (pi / 180); // radians conversion
	//std::cout << "cc2" << std::endl;
	/*
	std::vector<sf::Vertex> sircle;
	std::cout << sircle.size();
	int j;
	for (int i = 0; i < cheese; i++ )
	{
		j = sircle.size();
		if (i < j)
		{
			double xpoint = cos(angle) * (cord2[0] - cord[0]);
			double ypoint = 0 ;
			sircle.push_back;
			sircle[i] = ((sf::Vector2f(xpoint, ypoint), (sf::Color::Red));
		}
	}
	*/
	//this section creasts the first 2 points of the circle
	std::vector<sf::Vertex> sircle;
	sircle.push_back(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red, sf::Vector2f(0, 0))); // only way I can make it work these values are imadiatly written over
	sircle[0].position = sf::Vector2f(cord[0], cord[1]);
	sircle[0].color = sf::Color::Red;
	sircle[0].texCoords = sf::Vector2f(cord[0], cord[1]);
	sircle.push_back(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red, sf::Vector2f(0, 0))); // only way I can make it work these values are imadiatly written over
	sircle[1].position = sf::Vector2f(cord2[0], cord2[1]);
	sircle[1].color = sf::Color::Red;
	sircle[1].texCoords = sf::Vector2f(cord2[0], cord2[1]);
	//std::cout << "ab for" << std::endl;
	//this section then draws the rest of the cirle by adding more points for each degee
	for (int i = 2; i <= 360; i++)
	{
		if (i <= cheese)
		{
			//std::cout << "i<cheese" << i << std::endl;
			sircle.push_back(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red, sf::Vector2f(0, 0))); // only way I can make it work these values are imadiatly written over
			double xpoint = cos(i * (pi / 180)) * (cord2[0] - cord[0]) - sin(i * (pi / 180)) * (cord2[1] - cord[1]) + cord[0];
			double ypoint = sin(i * (pi / 180)) * (cord2[0] - cord[0]) + cos(i * (pi / 180)) * (cord2[1] - cord[1]) + cord[1];
			//sircle.push_back(sf::Vector2f(xpoint, ypoint), sf::Color::Red);
			sircle[i].position = sf::Vector2f(xpoint, ypoint);
			sircle[i].color = sf::Color::Red;
			sircle[i].texCoords = (sf::Vector2f(xpoint, ypoint));
		}
	}
	for (int i = 360; i > cheese; i--)
	{
		//sircle.pop_back();
	}
	//std::cout << sircle.size() << std::endl;
	// render
	//std::cout << "ab draw" << std::endl;
	(*dave).clear(sf::Color::Black);
	// now to draw a square
	//this section controlls the drawing of the armor display
	if (!((*richard) <= 0))
	{
		std::vector<sf::Vertex> cquaire;
		cquaire.resize(4);
		std::vector<sf::Vertex> cquaire2;
		cquaire2.resize(4);
		int xset = ((*richard) / 10);
		int yset = (xset) / (4 / 3);
		//outer
		cquaire[1].position = sf::Vector2f(0, 0);
		cquaire2[1].position = sf::Vector2f(xset, yset);

		cquaire[0].position = sf::Vector2f(0, y);
		cquaire2[0].position = sf::Vector2f(xset, y - yset);

		cquaire[2].position = sf::Vector2f(x, 0);
		cquaire2[2].position = sf::Vector2f(x - xset, yset);

		cquaire[3].position = sf::Vector2f(x, y);
		cquaire2[3].position = sf::Vector2f(x - xset, y - yset);


		for (int i = 0; i < cquaire.size(); i++)
		{
			cquaire[i].color = sf::Color::Blue;
			cquaire2[i].color = sf::Color::Black;
		}

		// now to do draw
		(*dave).draw(&cquaire[0], cquaire.size(), sf::Quads);
		(*dave).draw(&cquaire2[0], cquaire.size(), sf::Quads);
	}
	(*dave).draw(&sircle[0], sircle.size(), sf::TriangleFan);
	(*dave).display();
	}
}