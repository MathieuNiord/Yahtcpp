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

void coo_yahtzee::game::play() const
{
	for (int round = 0; round < 13; round++) {
		for (int player = 0; player < number_of_players_; player++) {
			//TODO player turn
		}
	}
}
