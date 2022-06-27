#pragma once
#include "Header.h"
#include "square.h"
class map_level_edditor
{
public:
//this was originaly set to private I have made it public so it can be accessed easier as otherwise I would have to write a function to access a function inside of a class
	level_modifercation_tile map[20][16];
public:
	void init_map();
	void print_map(sf::RenderWindow * windowpointer);
};