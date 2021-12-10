/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "player.h"

namespace coo_yahtzee {

	class game {

	public :

		game(int number_of_player);
		~game();

	private :

		int number_of_players_;
		std::vector<player*> players_;
		std::vector <player*> eliminated;
		std::vector<dice*> dices_;

		void play() const;


	};

}