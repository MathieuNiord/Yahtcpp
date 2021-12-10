/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

namespace coo_yahtzee {

	// Dice
	constexpr int min_dice_value = 1;
	constexpr int max_dice_value = 6;

	// Roll
	constexpr int number_of_dices = 5;
	constexpr int max_round = 3;

	// Figures
	constexpr int pair = 2;
	constexpr int three_of_kind = 3;
	constexpr int four_of_kind = 4;
	constexpr int max_yahtzee = 2;

	// Figures constant results
	constexpr int yahtzee_result = 50;
	constexpr int full_result = 25;

	// Score
	constexpr int bonus_start = 63;
	constexpr int bonus = 35;
	constexpr int max_superiors = 6;
	constexpr int max_inferiors = 7;

	// Game
	constexpr int total_rounds = 13;

}
