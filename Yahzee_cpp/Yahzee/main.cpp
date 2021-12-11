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

	int count = 1;

	std::vector<std::string*> players;

	players.push_back(new string("Mathieu"));
	players.push_back(new string("Gaetan"));
	players.push_back(new string("Hakim"));
	players.push_back(new string("Nicolas"));

	player_choices(2);

	//TODO call game constructor with nb_player

	return EXIT_SUCCESS;

}
