/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "player.h"
#include "ai_player.h"
namespace coo_yahtzee {

	class game {

	public :

		game(const int& nb_players, const int& mode = 0); // Multi mode
		game(const std::string& name, const int& nb_bots, const int& mode = 0); // Solo mode
		~game();

        void play();

	private :

		// --- Attributes ---
		const int mod_;
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