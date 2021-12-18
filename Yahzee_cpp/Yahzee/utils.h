/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"

namespace coo_yahtzee {

	// Return a random value
	static int get_random(const int& min, const int& max) {
		return rand() % max + min;
	}

	// Translate a string of numbers into a vector of the same numbers
	static std::vector<int> translate_to_vector(const std::string& s) {

		std::vector<int> positions;
		std::stringstream stream(s);

		int pos;
		std::string temp;

		while (!stream.eof()) {

			stream >> temp;

			if (std::stringstream(temp) >> pos)
				positions.push_back(pos);

			temp = "";
		}

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
