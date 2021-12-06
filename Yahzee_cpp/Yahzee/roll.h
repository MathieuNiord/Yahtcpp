/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <iostream>
#include <vector>
#include "dice.h"

namespace coo_yahtzee {

	constexpr int NUMBER_OF_DICES = 5;
	constexpr int MAX_ROUND = 3;

	class roll {

	public:

		roll();
		roll(const roll&);
		~roll();

	private:

		std::vector<dice> c_dices;
		int round_count = 0;

		// Roll all dices
		void roll_dices() const;

		// Roll one or more than one dice
		void roll_dice(std::vector<int> positions) const;

		// Get the count of a value among dices
		int get_number_of(const int& value) const;

	};

}

