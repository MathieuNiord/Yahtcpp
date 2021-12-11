/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "figure.h"
#include "roll.h"
#include "score.h"

namespace coo_yahtzee {

	class player {

	public:

		player(const std::string& name);
		~player();

		// --- Getter ---
		int get_score() const;

	protected:

		const std::string c_name_;
		std::vector<figure*> remaining_figures_;
		score* player_score_;
		bool eliminated_;

		// --- Setter ---
		void score_all() const;

	private:

		void play_round(std::vector<dice*>&);

		friend std::ostream& operator<<(std::ostream& out, const player&);
		friend class game;

	};

	std::ostream& operator<<(std::ostream& out, const player&);
}