/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"

namespace coo_yahtzee {

	// === ERRORS ===

	const std::string error_01("Votre choix est malheureusement indisponible pour le moment. SVP retentez.");
	const std::string error_02("On va fermer les yeux pour cette fois...On reprend depuis le depart.");
	const std::string error_03("Franchement, ca arrive a tout le monde de se tromper. On reprend.");
	const std::string error_04("Bah alors ? C'est pas une reponse ca...");
	const std::string error_05("Mince mais vous etes bigleux ??? C'est quoi cette reponse tecla ?");

	// Return a random value
	static int get_random(const int& min, const int& max) {
		return rand() % max + min;
	}

	// Return an error
	static std::string get_error() {

		const int which_one = get_random(0, 1000);

		switch (which_one % 5) {
		case 1: return "\n\n" + error_01 + "\n\n";
		case 2: return "\n\n" + error_02 + "\n\n";
		case 3: return "\n\n" + error_03 + "\n\n";
		case 4: return "\n\n" + error_04 + "\n\n";
		case 0: return "\n\n" + error_05 + "\n\n";
		default: return "\n\nCe choix n'existe pas.\n\n";
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

    static int get_input_int() {

        try {
            std::string line;
            std::getline(std::cin, line);
            return std::stoi(line);
        }

        catch (std::exception exception) {
			std::cout << get_error();
			std::cout << "Quelle est votre reponse ?\n\nReponse : ";
            return get_input_int();
        }
    }

    static std::vector<int> get_input_int_vector() {

		std::string s;
		getline(std::cin, s);
        std::vector<int> ans;
        std::stringstream stream(s);

        int pos;
        std::string temp;

        while (!stream.eof()) {

            stream >> temp;

            if (std::stringstream(temp) >> pos)
                ans.push_back(pos);

            temp = "";
        }

        return ans;
    }
}
