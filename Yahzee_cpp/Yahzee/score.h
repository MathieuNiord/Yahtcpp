/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "figure.h"
#include  "fig_superior.h"
#include "many_of_kind.h"
#include "full_house.h"
#include "yahtzee.h"
#include "straight.h"

namespace coo_yahtzee {

	class score {

	public:

		score();
		score(const score&);
		~score();

	private:

		int score_;
		std::vector<figure*> scored_superiors;
		std::vector<figure*> scored_inferiors;

		void init_inferiors();
		void init_superiors();

		// --- Setters ---
		void compute_score(); // Compute the current score
		void add_inf(figure*); // Add a figure to the inferior part
		void add_sup(figure*); // Add a figure to the superior part

		friend std::ostream& operator<<(std::ostream& out, const score&);
		friend class player;
	};

	std::ostream& operator<<(std::ostream& out, const score&);

}