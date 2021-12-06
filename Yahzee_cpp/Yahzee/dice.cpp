#include "dice.h"

#include <random>

void coo_yahtzee::dice::roll() {
	value = rand() % MAX + MIN;
}
