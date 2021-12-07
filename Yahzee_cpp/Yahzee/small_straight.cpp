#include "small_straight.h"

coo_yahtzee::inferior_figure::small_straight::small_straight()
	: figure("Petite suite")
{}

coo_yahtzee::inferior_figure::small_straight::small_straight(const small_straight& small_straight)
	: figure(small_straight.c_name)
{}
