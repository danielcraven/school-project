#include "constants.h"
#include "header.h"

//this page sets the values of constants that are not to change though it also sets the format for vectors as wel

void um::vector2dint::setx(int value)
{
	x = value;
}
void um::vector2dint::sety(int value)
{
	y = value;
}
int um::vector2dint::getx()
{
	return x;
}
int um::vector2dint::gety()
{
	return y;
}

void um::vector2dint::set_correct(bool pass)
{
	correct = pass;
}

void um::vector2dint::set_correct2(bool pass)
{
	correct2 = pass;
}

bool um::vector2dint::get_correct()
{
	return correct;
}

bool um::vector2dint::get_correct2()
{
	return correct2;
}

void U_C::setval()
{
	U_C::menu_resolution.setx(1274);
	U_C::menu_resolution.sety(817);
	U_C::button_size.setx(250);
	U_C::button_size.sety(50);
	text_size = 24;
	menu_text_font.loadFromFile("assets/LuxuriousRoman-Regular.ttf");
}