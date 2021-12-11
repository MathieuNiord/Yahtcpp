/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"

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

		friend class roll;
		friend class figure;

	};

}