#include "roll.h"

void coo_yahtzee::roll::roll_dice(std::vector<int> positions) const {

	for (int pos : positions)
		c_dices.at(pos).roll();

}
