/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <iostream>
#include <vector>
#include "fig_inferior.h"
#include  "fig_superior.h"

namespace coo_yahtzee {

	class score {

	public:

		score();
		score(const score&);
		~score();

	private:

		std::vector<fig_superior*> scored_superiors;
		std::vector<fig_inferior*> scored_inferiors;

		friend class player;
	};

}