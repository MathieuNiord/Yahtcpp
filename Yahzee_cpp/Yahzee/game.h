/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "player.h"

namespace coo_yahtzee {

	class game {

	public :

		game(const int& number_of_player);
		~game();

	private :

		const int number_of_players_;
		std::vector<player*> players_;
		std::vector<dice*> dices_;

		void play() const;

	};

}