#include "yahtzee.h"

coo_yahtzee::inferior_figure::yahtzee::yahtzee()
	: figure("Yahtzee") {
	count = 0;
}

coo_yahtzee::inferior_figure::yahtzee::yahtzee(const yahtzee& yahtzee)
	: figure(yahtzee.c_name) {
	count = yahtzee.count;
}

coo_yahtzee::inferior_figure::yahtzee::~yahtzee()
{
}
