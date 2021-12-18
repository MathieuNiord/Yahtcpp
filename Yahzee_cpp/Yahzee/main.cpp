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

	/*int nb_player;

	std::cout << "==Yahtzee==" << std::endl;
	std::cout << "Combien de joueurs : ";
	std::cin >> nb_player;

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


	for (int i = 0; i < 3; i++)
		math->play_turn(dices);

	//TODO call game constructor with nb_player

	return EXIT_SUCCESS;

}
