/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"

namespace coo_yahtzee {

	// Return a random value
	static int get_random(const int& min, const int& max) {
		return rand() % max + min;
	}

	// Return a boss name
	static std::string get_enemy_tag() {
		const int which_one = get_random(0, bosses.size());
		return bosses.at(which_one);
	}

	// Return an error
	static std::string get_error() {

		const int which_one = get_random(0, 1000);

		switch (which_one % 5) {
		case 1: return "\n\nPROGRAMME : " + error_01 + "\n\n";
		case 2: return "\n\nPROGRAMME : " + error_02 + "\n\n";
		case 3: return "\n\nPROGRAMME : " + error_03 + "\n\n";
		case 4: return "\n\nPROGRAMME : " + error_04 + "\n\n";
		case 0: return "\n\nPROGRAMME : " + error_05 + "\n\n";
		default: return "\n\nPROGRAMME : Ce choix n'existe pas.\n\n";
		}
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

	static void clear_screen() {
		std::cout << "\033[2J\033[1;1H"; // For cleaning
	}

	// Wait a char and clean the screen
	static void wait_and_clean_screen(const std::string& msg = "Appuyez sur Entree pour continuer...") {
		std::cout << msg;
		std::getchar();
		clear_screen();
	}

	static int get_input_int(int min = INT_MIN, int max = INT_MAX) {

        try {
            std::string line;
            std::getline(std::cin, line);
            return std::stoi(line);
        }

        catch (std::exception exception) {
			std::cout << get_error();
			std::cout << "Quelle est votre reponse ?\n\nReponse : ";
            return get_input_int(min, max);
        }
    }

}
