#include "full_house.h"

coo_yahtzee::inferior_figure::full_house::full_house()
	: figure("Full")
{}

coo_yahtzee::inferior_figure::full_house::full_house(const full_house& full_house)
	: figure(full_house.c_name)
{}
