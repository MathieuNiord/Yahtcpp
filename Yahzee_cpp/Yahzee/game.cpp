#include "game.h"

coo_yahtzee::game::game(const int& number_of_player) : number_of_players_(number_of_player)
{

	for (int i = 0; i < number_of_player; i++)
	{
		std::string name;
		std::cout << "Please give a name to the player " << i << ": ";
		std::cin >> name;
		players_.push_back(new player(name));
	}

	for (int i = 0; i < number_of_dices; i++) {
		dices_.push_back(new dice());
	}
}
