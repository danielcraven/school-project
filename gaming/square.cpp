#include "square.h"
#include "button.h"
square::square()//base class will be over ridden
{
	drawn_element = sf::VertexArray(sf::Quads, 4);
}

sf::VertexArray* square::passout_drawn_element()// allows the sfml drawn part to be outputted so it can be drawn
{
	return &drawn_element;
}

void square::update_drawn_element()//this ensures that the drawn element is in the correct place for the square, I created my own method of holding the cordinates and only use sfml when I am amout to draw them, this is becuase I am unsure as to sfml's inner worksing and thus cannot interact with it idealy
{
	//assingn points to drawn element
	(drawn_element)[0].position = sf::Vector2f(points[0].getx(),points[0].gety());
	(drawn_element)[1].position = sf::Vector2f(points[1].getx(),points[1].gety());
	(drawn_element)[2].position = sf::Vector2f(points[2].getx(),points[2].gety());
	(drawn_element)[3].position = sf::Vector2f(points[3].getx(),points[3].gety());
	//colour points
}
square::~square()
{
	//std::cout << "square is being deleted " << std::endl;
	//delete drawn_element;
}
void square::print_cords()//used in development so I could ensure squares were placed in the right location
{
	using namespace std;
	for (int i = 0; i < 4 ; i++)
	{
		cout << points[i].getx() << " " << points[i].gety() << endl;
	}
}

void button_assinged_square::set_points_for_button(int button_number, U_C uc)//this seciton is used in the menus so that a button can be placed in the right place on the screen, this also means that the buttons can be resisesed
{
	int number_of_button_slots = uc.menu_resolution.gety() / uc.button_size.gety();
	int sp = number_of_button_slots - 2 ; //done to keep short
	points[0].setx(( uc.menu_resolution.getx() / 2 )  - (uc.button_size.getx()/2));
	points[0].sety(((uc.menu_resolution.gety() / sp) * button_number + uc.button_size.gety()));
	points[1].setx((uc.menu_resolution.getx() / 2) - (uc.button_size.getx() / 2));
	points[1].sety(((uc.menu_resolution.gety() / sp) * button_number));
	points[2].setx((uc.menu_resolution.getx() / 2) + (uc.button_size.getx()/2));
	points[2].sety(((uc.menu_resolution.gety() / sp) * button_number));
	points[3].setx((uc.menu_resolution.getx() / 2) + (uc.button_size.getx()/2));
	points[3].sety( ((uc.menu_resolution.gety() / sp) * button_number)+uc.button_size.gety() );
};

void button_square_text::set_text(std::string pass_text,um::vector2dint* pass_pointer_mouse_cords)//this is where the squyare button is given text by the element it is stored in that being the button class
{
	square_text = pass_text;
	mouse_cords = pass_pointer_mouse_cords;
};
void button_square_text::attach_text() //this section creates the drawn element for the text
{
	uc.setval();
	square_text_drawn_element.setFont(uc.menu_text_font);
	square_text_drawn_element.setCharacterSize(uc.text_size);
	square_text_drawn_element.setString(square_text);
	//this is where the points are set
	double middlex = points[1].getx() + ((points[3].getx() - points[1].getx())/2);
	double point_textx = middlex - ((square_text.length()*uc.text_size)/4);
	float x = point_textx;
	double middley = points[1].gety() + (uc.button_size.gety() / 4);
	float y = middley - (uc.text_size/4);
	//the points have being set
	square_text_drawn_element.setPosition(x, y);
}
sf::Text* button_square_text::passout_text_drawn_element()//this outputs the text sfml compoinent so it can be drawn
{
	return &square_text_drawn_element;
}
void button_square_text::poll_square_for_contact()//this is to cheak if a button in the menu has being pressed and also to adjust its colour
{
	pressed = false;
	//std::cout << "start of mouse cords  " << mouse_cords << std::endl;
	//std::cout << points[0].gety() << "  " << (*mouse_cords).gety() << "&&" << points[1].gety() << "  " << (*mouse_cords).gety() << std::endl;
	if ((points[0].gety() > (*mouse_cords).gety() && points[1].gety() < (*mouse_cords).gety()) && ((*mouse_cords).getx() > points[0].getx() && (*mouse_cords).getx() < points[2].getx()))
	{
		(drawn_element)[0].color = sf::Color(0xff000051);
		(drawn_element)[1].color = sf::Color(0x00ff0051);
		(drawn_element)[2].color = sf::Color(0x0000ff51);
		(drawn_element)[3].color = sf::Color(0x00000051);
		square_text_drawn_element.setFillColor(sf::Color(0xffffffff));
		pressed = false;
		if ((*mouse_cords).get_correct() == true)
		{
			(drawn_element)[0].color = sf::Color(0x00000000);
			(drawn_element)[1].color = sf::Color(0x00000000);
			(drawn_element)[2].color = sf::Color(0x00000000);
			(drawn_element)[3].color = sf::Color(0x00000000);
			square_text_drawn_element.setFillColor(sf::Color(0x00000000));
			pressed = true;
		}
	}
	else
	{
		(drawn_element)[0].color = sf::Color(0xff0000ff);
		(drawn_element)[1].color = sf::Color(0x00ff00ff);
		(drawn_element)[2].color = sf::Color(0x0000ffff);
		(drawn_element)[3].color = sf::Color(0x000000ff);
		square_text_drawn_element.setFillColor(sf::Color(0x000000ff));
		pressed = false;
	}

	//std::cout << pressed << "it is obvius" << std::endl;
}

void level_modifercation_tile::testforpress(um::vector2dint* mouse_cords,int type_set)//this is to cheak if a tile in the level eddit has being pressed and thus to change its value
{
	/*
	std::cout << points[0].getx() << " cheese test " << points[0].gety() << std::endl;
	std::cout << points[1].getx() << " cheese test " << points[1].gety() << std::endl;
	std::cout << points[2].getx() << " cheese test " << points[2].gety() << std::endl;
	std::cout << points[3].getx() << " cheese test " << points[3].gety() << std::endl;
	std::cout << (*mouse_cords).getx() << "cheddar test" << (*mouse_cords).gety() << std::endl;
	std::cout << "by all means these should be true" << std::endl;
	*/
	pressed = false;
	if (points[0].gety() < (*mouse_cords).gety() && points[2].gety() > (*mouse_cords).gety() /**/ &&/**/ points[0].getx() < (*mouse_cords).getx() && points[2].getx() > (*mouse_cords).getx())
	{
		pressed = true;
		if ((*mouse_cords).get_correct())
		{
			type = 1;
		}
		if ((*mouse_cords).get_correct2())
		{
			type = 0;
		}
	}
}

int level_modifercation_tile::gettype()
{
	return type;
}
