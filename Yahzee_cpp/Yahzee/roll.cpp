/* Authors : Frejoux G. & Niord M. */

#include "roll.h"

coo_yahtzee::roll::roll(const std::vector<dice*>& dices)
	: c_dices_(dices), round_count_(0)
{}

coo_yahtzee::roll::roll(const roll& r)
	: c_dices_(r.c_dices_), round_count_(r.round_count_)
{}

coo_yahtzee::roll::~roll() {

	for (const dice* d : c_dices_)
			delete d;

	c_dices_.clear();
}

void coo_yahtzee::roll::roll_dices() {

	for (dice* d : c_dices_)
		d->roll();

	round_count_++;
}

void coo_yahtzee::roll::roll_dice(const	std::vector<int>& positions) {

	for (const int& pos : positions)
		if (pos > min_dice_value - 1 && pos < max_dice_value - 1)
			c_dices_.at(pos)->roll();

	round_count_++;
}

int coo_yahtzee::roll::get_number_of(const int& value) const {

	int counter = 0;

	for (const dice* d : c_dices_)
		if (d->value == value)
			counter++;

	return counter;
}
