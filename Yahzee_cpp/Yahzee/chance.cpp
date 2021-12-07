#include "chance.h"

coo_yahtzee::inferior_figure::chance::chance()
	: figure("Chance") {
}

coo_yahtzee::inferior_figure::chance::chance(const chance& chance)
	: figure(chance.c_name) {
}

coo_yahtzee::inferior_figure::chance::~chance()
{
}
