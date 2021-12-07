#include "large_straight.h"

coo_yahtzee::inferior_figure::large_straight::large_straight()
	: figure("Grande suite")
{}

coo_yahtzee::inferior_figure::large_straight::large_straight(const large_straight& large_straight)
	: figure(large_straight.c_name)
{}

coo_yahtzee::inferior_figure::large_straight::~large_straight()
{
}
