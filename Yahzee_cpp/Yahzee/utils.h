#pragma once

#include "resources.h"
#include "dice.h"
#include "player.h"

namespace coo_yahtzee {

	class figure;
	class score;
	class player;

	inline bool compare_dice_pointers(const dice* d01, const dice* d02) {
		return (d01->get_value() < d02->get_value());
	}

	/*inline bool compare_player_pointers(const player* p01, const player* p02) {
		return (p01->get_score() <= p02->get_score());
	}*/

	static void sort_dices(std::vector<dice*>& dices) {
		std::sort(dices.begin(), dices.end(), compare_dice_pointers);
	}

	/*static void sort_players(std::vector<player*>& players) {
		std::sort(players.begin(), players.end(), compare_player_pointers);
	}*/

	// Translate a string of numbers into a vector of the same numbers
	static std::vector<int> translate_to_vector(const std::string& s) {

		std::vector<int> positions(s.begin(), s.end());
		std::stringstream stream(s);

		int pos;
		while (stream >> pos)
			positions.push_back(pos);

		return positions;
	}

	// Will check if the player input is an integer
	static bool check_input_is_integer(const std::string& input) {

		for (const char& c : input)
			if (!isdigit(c))
				return false;

		return true;
	}

}
