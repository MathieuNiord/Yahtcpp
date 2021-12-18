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

    static int get_input_int(){
        try{
            std::string line;
            std::getline(std::cin, line);
            return std::stoi(line);
        }
        catch (std::exception exception) {
            std::cout << "Nous souhaitons un entier ici !\nValeur : ";
            return get_input_int();
        }
    }


    static std::string get_input_string(){
        std::string line;
        return line;
    }

    static std::vector<int> get_input_int_vector(){
        std::string s = get_input_string();
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
