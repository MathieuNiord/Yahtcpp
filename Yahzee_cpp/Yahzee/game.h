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

		static void sort_players(std::vector<player*>& players) {
			std::sort(players.begin(), players.end(), player::compare_player_pointers);
		}


	};

}