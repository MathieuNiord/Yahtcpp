/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "dice.h"

namespace coo_yahtzee {

	class roll {

	public:

		roll(const std::vector<dice*>& dices);
		roll(const roll&);
		~roll();

	private:

		std::vector<dice*> dices_;
		int round_count_;

		// Roll all dices
		void roll_dices();

		// Roll one or several dices by their positions
		void roll_dice(const std::vector<int>& positions);

		// Get the count of a value among dices
		int get_number_of(const int& value) const;

		// Sort dices
		void sort();

	};

}

