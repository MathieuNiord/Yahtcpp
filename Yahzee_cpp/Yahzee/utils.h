#pragma once

#include "resources.h"

namespace coo_yahtzee {

	// Return a random value
	static int get_random(const int& min, const int& max) {
		srand((unsigned)time(0));
		return rand() % max + min;
	}

	// Translate a string of numbers into a vector of the same numbers
	static std::vector<int> translate_to_vector(const std::string& s) {

		std::vector<int> positions;
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
