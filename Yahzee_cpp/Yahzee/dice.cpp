/* Authors : Frejoux G. & Niord M. */

#include "dice.h"

coo_yahtzee::dice::dice() {
	value_ = max_dice_value;
}

coo_yahtzee::dice::dice(const dice& d) {
	value_ = d.value_;
}

int coo_yahtzee::dice::get_value() const {
	return value_;
}

void coo_yahtzee::dice::roll() {
	value_ = get_random(min_dice_value, max_dice_value);
}

bool coo_yahtzee::dice::operator<(const dice& d) const {
	return value_ < d.value_;
}

std::string coo_yahtzee::dice::to_string() const {
	return "[" + std::to_string(value_) + "]";
}