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
		~score();

	private:

		int score_;
		std::vector<figure*> superiors;
		std::vector<figure*> inferiors;
		int remaining_count_;

		// --- Methods ---

		void init_inferiors();
		void init_superiors();

		// --- Setters ---
		void compute_score(); // Compute the current score
		void add_inf(figure*); // Add a figure to the inferior part
		void add_sup(figure*); // Add a figure to the superior part
		void set_score(int position, const std::vector<dice*>& dices); // Scored a figure at a given position
		void score_all(); // Set the score of all remaining figures

		// --- Display ---
		void display_figure_possibility(int& count, const figure* fig, const std::vector<dice*>& dices) const;
		void display_score(std::ostream& out) const;
		void display_possibilities(const std::vector<dice*>& dices) const;

		friend std::ostream& operator<<(std::ostream& out, const score&);
		friend class player;
	};

	std::ostream& operator<<(std::ostream& out, const score&);

}