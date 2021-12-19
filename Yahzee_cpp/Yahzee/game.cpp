/* Authors : Frejoux G. & Niord M. */

#include "game.h"

coo_yahtzee::game::game(const int& nb_players, const int& mod)
	: number_of_players_(nb_players), mod_(mod) {

	players_.reserve(nb_players);

	int nb_human;
	std::cout << "How many human player : ";

	nb_human = get_input_int(1, nb_players);

	for (int i = 0; i < nb_human; i++) {
		std::string name;
		std::cout << "Donnez un nom au joueur " << i + 1 << " : ";
		std::getline(std::cin, name);
		players_.push_back(new player(name));
		std::cout << "\nJoueur " << name << " cree.\n\n";
	}

	for (int i = nb_human; i < nb_players; i++) {
		std::string name;
		std::cout << "Donnez un nom du robot " << i + 1 << " : ";
		std::getline(std::cin, name);
		players_.push_back(new ai_player(name));
		std::cout << "\Robot " << name << " cree.\n\n";
	}

	for (int i = 0; i < number_of_dices; i++) {
		dices_.push_back(new dice);
	}

	eliminated_count_ = 0;
}

void coo_yahtzee::game::play() {

	int round = 0;

	// While the game isn't finished and the number of active players is upper than 1
	while (round < total_rounds && eliminated_count_ < number_of_players_ - 1) {

		for (int player = 0; player < number_of_players_; player++) {

			if (!players_.at(player)->eliminated_) {

				std::cout << "\n\n========== TOUR " << round + 1 << " ==========\n\n";
				std::cout << "Au tour de " << players_.at(player)->c_name_ << " (Joueur " << player + 1 << ")\n\n";

				players_.at(player)->play_turn(dices_);

				// If at the end of his/her turn the player is eliminated,
				// the game increments its counter
				if (players_.at(player)->eliminated_)
					eliminated_count_++;
			}
		}

		round++;
	}
    finish();
}

void coo_yahtzee::game::finish() {

    std::string winner("Gagnant : ");

	// The program compute the score of all the players
	for (const player* player : players_)
		player->score_all();

	// The program sorts the list of players based on their scores
	sort_players();

	// The program finds the winner
	// (in case in the player were eliminated, he/she can not win)
	for (const player* player : players_) {
		if (!player->eliminated_) {
			winner.append(player->c_name_);
			break;
		}
	}

	std::cout
		<< "\n\n\t =========== PARTIE TERMINEE ===========\n"
		<< "\t|                                       |\n";

	for (const player* player : players_)
		display_player_score(player);

	std::cout << "\t|                                       |\n";

	if (eliminated_count_ != number_of_players_)
		std::cout
			<< "\t| " << std::left << std::setw(38) << winner << "|\n";

	else
		std::cout
			<< "\t| " << std::left << std::setw(38) << "Aucun gagnant, que des loosers " << "|\n";

	std::cout
		<< "\t|                                       |\n"
		<< "\t =======================================\n\n";

}

void coo_yahtzee::game::sort_players() {
	std::sort(players_.begin(), players_.end(), player::compare_player_pointers);
}

void coo_yahtzee::game::display_player_score(const player* p) const {

	std::string eliminate;

	if (p->eliminated_)
		eliminate = " (Eliminate)";

	const std::string player = p->c_name_ + eliminate + " : " + std::to_string(p->get_score_result());

	std::cout
		<< "\t| " << std::left << std::setw(38) << player << "|\n";
}

coo_yahtzee::game::~game() {

    for (const player* player : players_)
		delete player;

    for (const dice* dice : dices_)
		delete dice;

	players_.clear();
	dices_.clear();
}
