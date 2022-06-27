#pragma once
#include "header.h"
#include "constants.h"

namespace um
{
	class vector2dint
	{
	private:
		int x;
		int y;
		bool correct;
		bool correct2;
	public:
		void setx(int x);
		void sety(int y);
		int getx();
		int gety();
		void set_correct(bool pass);
		void set_correct2(bool pass);
		bool get_correct();
		bool get_correct2();
	};
}

class U_C
{
public:
	// lack of static is unideal
	int gravity;
	void setval();
	um::vector2dint button_size;
	um::vector2dint menu_resolution;
	sf::Font menu_text_font;
	int text_size;
};