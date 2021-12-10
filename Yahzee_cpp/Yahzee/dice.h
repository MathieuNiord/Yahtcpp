/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"

namespace coo_yahtzee {

	class dice {

	public:

		// Getter
		int get_value() const;

	private:

		int value;

		dice(const int& value);

		void roll();
		bool operator<(const dice&) const;

		friend class roll;
		friend class figure;

	};

}