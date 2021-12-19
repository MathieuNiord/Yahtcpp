/* Authors : Frejoux G. & Niord M. */

#pragma once
#include "player.h"
namespace coo_yahtzee {

	class ai_player : public player
	{
	public:
		ai_player(const std::string& name);
	protected:
		void play_round(roll&) override;

	};
}
