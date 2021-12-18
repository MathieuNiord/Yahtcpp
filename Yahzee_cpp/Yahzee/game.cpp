/* Authors : Frejoux G. & Niord M. */

#include "game.h"

coo_yahtzee::game::game(const int& nb_players)
	: number_of_players_(nb_players) {

	players_.reserve(nb_players);

	for (int i = 0; i < nb_players; i++) {
		std::string name;
		std::cout << "Donnez un nom au joueur " << i+1 << ": ";
		std::cin >> name;
		players_.push_back(new player(name));
	}

	for (int i = 0; i < number_of_dices; i++) {
		dices_.push_back(new dice);
	}

	eliminated_count_ = 0;
}

void coo_yahtzee::game::play()
{
	for (int round = 0; round < total_rounds; round++) {

		for (int player = 0; player < number_of_players_; player++) {

			//TODO player turn

			if (eliminated_count_ == number_of_players_ ) {
				return finish();
			}

			std::cout << "========== TOUR " << round + 1 << " ==========\n\n";
			std::cout << "Au tour de " << players_.at(player)->c_name_ << " (Joueur " << player + 1 << ")\n\n";

			players_.at(player)->play_turn(dices_);
		}

	}
}

void coo_yahtzee::game::finish() {

	for (player* player : players_)
		player->score_all();

	//TODO : finish the game

}

coo_yahtzee::game::~game() {
    for (const auto &item : players_) delete item;
    for (const auto &item : dices_) delete item;
}
