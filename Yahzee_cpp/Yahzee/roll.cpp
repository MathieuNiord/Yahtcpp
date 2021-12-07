#include "roll.h"

coo_yahtzee::roll::roll(const std::vector<dice*>& dices)
	: c_dices(dices), round_count(0)
{}

coo_yahtzee::roll::roll(const roll& r)
	: c_dices(r.c_dices), round_count(r.round_count)
{}

coo_yahtzee::roll::~roll() {

	for (const dice* d : c_dices)
			delete d;

	c_dices.clear();
}

void coo_yahtzee::roll::roll_dices() {

	for (dice* d : c_dices)
		d->roll();

	round_count++;
}

void coo_yahtzee::roll::roll_dice(const	std::vector<int>& positions) {

	for (const int& pos : positions)
		if (pos > MIN - 1 && pos < MAX - 1)
			c_dices.at(pos)->roll();

	round_count++;
}

int coo_yahtzee::roll::get_number_of(const int& value) const {

	int counter = 0;

	for (const dice* d : c_dices)
		if (d->value == value)
			counter++;

	return counter;
}
