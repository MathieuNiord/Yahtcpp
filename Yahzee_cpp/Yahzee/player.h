/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <iostream>
#include <vector>
#include "figure.h"
#include "roll.h"
#include "score.h"

namespace coo_yahtzee {

	class player {

	public:

		player(const int& id, const std::string& name);
		player(const player&);
		~player();

	protected:

		const int c_id;
		const std::string c_name;
		std::vector<figure*> remaining_figures;
		score* player_score;

	private:

		// Initialize the figure's list at the beginning of the game
		void init_figures() const;

		friend std::ostream& operator<<(std::ostream& out, const player&);

	};

	std::ostream& operator<<(std::ostream& out, const player&);
}