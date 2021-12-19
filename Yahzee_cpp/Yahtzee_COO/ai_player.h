/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "player.h"

namespace coo_yahtzee {

	class ai_player : public player {

	public:

		ai_player(const std::string& name);

	private:

		// --- Methods ---
		void choose_figure(roll& p_roll) const;
		void play_turn(const std::vector<dice*>&) override;
		void play_round(roll&) override;

		// Tests

	};
}
