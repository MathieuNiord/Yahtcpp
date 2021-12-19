/* Authors : Frejoux G. & Niord M. */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <climits>

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

	// Player
	constexpr int max_advertisement = 3;
	constexpr int elimination_code = 81647;	// Elimination code
	constexpr int char_error_code = 45616;	// Error code when input is a string rather than an integer

	// AI
	constexpr int min_score_ai = 10;

	// Game
	constexpr int total_rounds = 13;

	// Errors
	const std::string error_01("Votre choix est malheureusement indisponible pour le moment. SVP retentez.");
	const std::string error_02("On va fermer les yeux pour cette fois...On reprend depuis le depart.");
	const std::string error_03("Franchement, ca arrive a tout le monde de se tromper. On reprend.");
	const std::string error_04("Bah alors ? C'est pas une reponse ca...");
	const std::string error_05("Mince mais vous etes bigleux ??? C'est quoi cette reponse tecla ?");

	// AI names
	const std::vector <std::string> bosses =
	{
		"Revolver Ocelot",
		"Sarah Kerrigan",
		"Arthas Menethil",
		"GLadOS",
		"Sephiroth",
		"Dark Malak",
		"Hakim Berrier-Felhaouari",
		"Nicolas"
	};

}
