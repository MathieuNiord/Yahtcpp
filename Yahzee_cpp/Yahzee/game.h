/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "player.h"

namespace coo_yahtzee {

	class game {

	public :

		game(const int& nb_of_player);
		~game();

        void play();

	private :

		const int number_of_players_;
		std::vector<player*> players_;
		std::vector<dice*> dices_;
		int eliminated_count_;

		// --- Methods ---

		void finish();
		void sort_players();

		// --- Display ---
		void display_player_score(const player*) const;

	};

}