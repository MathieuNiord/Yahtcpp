/* Authors : Frejoux G. & Niord M. */

#include "dice.h"

#include <random>

int coo_yahtzee::dice::get_value() const {
	return value;
}

void coo_yahtzee::dice::roll() {
	value = rand() % max_dice_value + min_dice_value;
}

bool coo_yahtzee::dice::operator<(const dice& d) const {
	return value < d.value;
}
