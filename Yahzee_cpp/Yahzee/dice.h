/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "utils.h"

namespace coo_yahtzee {

	class dice {

	public:

		dice();
		dice(const dice&);

		// --- Getter ---
		int get_value() const;

		// --- Display ---
		std::string to_string() const;

	private:

		// --- Attributes ---
		int value_;

		// --- Methods ---
		void roll();

		// --- Comparison ---
		bool operator<(const dice&) const;
		static bool compare_dice_pointers(const dice* d01, const dice* d02) {
			return (d01->get_value() < d02->get_value());
		}

		// Friends
		friend class roll;
		friend class figure;

		// Tests
		friend class Test_Roll;

	};
}