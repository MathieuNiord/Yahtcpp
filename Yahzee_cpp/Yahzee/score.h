/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <iostream>
#include <vector>
#include "fig_inferior.h"
#include  "fig_superior.h"

namespace coo_yahtzee {

	constexpr int BONUS_START = 63;
	constexpr int BONUS = 35;

	constexpr int MAX_SUPERIORS = 6;
	constexpr int MAX_INFERIORS = 7;

	constexpr int ONE = 1;
	constexpr int TWO = 2;
	constexpr int THREE = 3;
	constexpr int FOUR = 4;
	constexpr int FIVE = 5;
	constexpr int SIX = 6;

	constexpr int VALUES[6] = {ONE, TWO, THREE, FOUR, FIVE, SIX};

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