/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "utils.h"

namespace coo_yahtzee {

	class dice {

	public:

		dice();

		//test
		void roll();

		// Getter
		int get_value() const;

	private:

		int value_;

		bool operator<(const dice&) const;

		static bool compare_dice_pointers(const dice* d01, const dice* d02) {
			return (d01->get_value() < d02->get_value());
		}

		friend class roll;
		friend class figure;
		friend class test_figure;

	};

}