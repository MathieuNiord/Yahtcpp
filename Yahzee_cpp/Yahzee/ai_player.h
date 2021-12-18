/* Authors : Frejoux G. & Niord M. */

#pragma once
#include "player.h"
namespace coo_yahtzee {

	class ai_player : public player
	{
	protected:
		void play_round(roll&) override;

	};
}
