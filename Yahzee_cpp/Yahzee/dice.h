/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"

namespace coo_yahtzee {

	class dice {

	public:

		dice();

		// Getter
		int get_value() const;

	private:

		int value_;

		void roll();
		bool operator<(const dice&) const;

		friend class roll;
		friend class figure;

	};

}