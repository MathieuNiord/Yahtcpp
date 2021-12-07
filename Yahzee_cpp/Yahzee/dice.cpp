#include "dice.h"

#include <random>

int coo_yahtzee::dice::get_value() const {
	return value;
}

void coo_yahtzee::dice::roll() {
	value = rand() % MAX + MIN;
}
