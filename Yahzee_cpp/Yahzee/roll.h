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

		roll(const std::vector<dice*>& dices);
		roll(const roll&);
		~roll();

	private:

		std::vector<dice*> c_dices;
		int round_count;

		// Roll all dices
		void roll_dices();

		// Roll one or several dices by their positions
		void roll_dice(const std::vector<int>& positions);

		// Get the count of a value among dices
		int get_number_of(const int& value) const;

	};

}

