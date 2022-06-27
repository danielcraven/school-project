#pragma once
#include "header.h"
#include "constants.h"
class level_edditor_inputs
{
	private:
	sf::Event event;
	sf::RenderWindow* window_pointer;
	public:
	um::vector2dint mouse_cords;
	public:
	level_edditor_inputs(sf::RenderWindow* pass_pointer);
	void mouse_gather();
	bool z;
};