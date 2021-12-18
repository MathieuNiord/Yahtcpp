/* Authors : Frejoux G. & Niord M. */

#include "game.h"

coo_yahtzee::game::game(const int& nb_players)
	: number_of_players_(nb_players) {

	players_.reserve(nb_players);

	for (int i = 0; i < nb_players; i++) {
		std::string name;
		std::cout << "Donnez un nom au joueur " << i+1 << ": ";
		std::getline(std::cin, name);
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


			std::cout << "========== TOUR " << round + 1 << " ==========\n\n";
			std::cout << "Au tour de " << players_.at(player)->c_name_ << " (Joueur " << player + 1 << ")\n\n";

			players_.at(player)->play_turn(dices_);
		}

	}
    finish();
}

void coo_yahtzee::game::finish() {
    int score = -1;
    player* winner;
    for(int i = 0; i < number_of_players_; i++){

        players_.at(i)->score_all();

        if(players_.at(i)->get_score() > score){
            score = players_.at(i)->get_score();
            winner = players_.at(i);
        }

    }

	//TODO : finish the game

    std::cout << " =========== PARTIE TERMINEE ===========\n"
                 "|                                       |\n";
    for (const auto &item : players_){
        std::cout << "| " << item->c_name_ << " : " << item->get_score() <<"     |\n";
    }
    std::cout << "|                                       |\n"
                 " =======================================\n";

    std::cout << "Gagnant : " << winner->c_name_;

}

coo_yahtzee::game::~game() {
    for (const auto &item : players_) delete item;
    for (const auto &item : dices_) delete item;
}
