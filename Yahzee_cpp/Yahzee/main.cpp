/* Authors : Frejoux G. & Niord M. */

#include <iomanip>
#include <iostream>

#include "display.h"
#include "resources.h"
#include "utils.h"
#include "game.h"

using namespace std;
using namespace coo_yahtzee;

int main(int argc, char* argv[]) {

	srand((unsigned)time(0));

	/*int nb_player;
	 *std::string input;

	std::cout << "==Yahtzee==" << std::endl;
	std::cout << "Combien de joueurs : ";
	std::getline(std::cin, input);


	if (nb_player <= 0)
		return speedrun();*/

	/*int count = 1;

	std::vector<std::string*> players;

	players.push_back(new string("Mathieu"));
	players.push_back(new string("Gaetan"));
	players.push_back(new string("Hakim"));
	players.push_back(new string("Nicolas"));*/

	std::vector<dice*> dices;
	dices.reserve(5);

	for (int i = 0; i < 5; i++) {
		dices.push_back(new dice);
	}

	player* math = new player("Mathieu");


	for (int i = 0; i < 14; i++) {
		std::cout << "TOUR " << i + 1 << "\n\n";
		math->play_turn(dices);
	}

	std::cout << *(math->player_score_);

	//TODO call game constructor with nb_player

	return EXIT_SUCCESS;

}
