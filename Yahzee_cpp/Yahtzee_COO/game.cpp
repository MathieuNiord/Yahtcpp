/* Authors : Frejoux G. & Niord M. */

#include "game.h"

coo_yahtzee::game::game(const int& nb_players, const int& mode)
	: mod_(mode), number_of_players_(nb_players) {

	players_.reserve(number_of_players_);

	for (int i = 0; i < nb_players; i++) {
		std::string name;
		std::cout << "\nDonnez un nom au joueur " << i + 1 << " : ";
		std::getline(std::cin, name);
		players_.push_back(new player(name));
		std::cout << "\nJoueur " << name << " cree.\n\n";
	}

	for (int i = 0; i < number_of_dices; i++)
		dices_.push_back(new dice);

	eliminated_count_ = 0;
}

coo_yahtzee::game::game(const std::string& name, const int& nb_bots, const int& mode)
	: mod_(mode), number_of_players_(nb_bots + 1) {

	players_.reserve(number_of_players_);
	players_.push_back(new player(name));

	std::cout << std::endl << std::endl;

	for (int i = 0; i < nb_bots; i++) {
		players_.push_back(new ai_player(get_enemy_tag()));
		std::cout << "Bot " << players_.at(i + 1)->c_name_ << " cree.\n";
	}

	for (int i = 0; i < number_of_dices; i++)
		dices_.push_back(new dice);

	eliminated_count_ = 0;
}

coo_yahtzee::game::~game() {

	for (const player* player : players_)
		delete player;

	for (const dice* dice : dices_)
		delete dice;

	players_.clear();
	dices_.clear();
}

void coo_yahtzee::game::play() {

	int round = 0;

	wait_and_clean_screen("\nAppuyez sur Entree pour lancer le jeu...");

	// While the game isn't finished and the number of active players is upper than 1
	while (round < total_rounds && eliminated_count_ < number_of_players_ - 1) {

		for (int player = 0; player < number_of_players_; player++) {

			// If the player is not already eliminated, he/she can play
			if (!players_.at(player)->eliminated_) {

				std::string advertisements;

				if (players_.at(player)->advertise_count_ > 0)
					advertisements.append(" [AVERTISSMENTS] : " + std::to_string(players_.at(player)->advertise_count_));

				std::cout << "\n\nAu tour de " << players_.at(player)->c_name_ << " (Joueur " << player + 1 << ")" << advertisements << "\n\n";

				players_.at(player)->play_turn(dices_);

				// If at the end of his/her turn the player is eliminated,
				// the game increments its counter
				if (players_.at(player)->eliminated_)
					eliminated_count_++;

				wait_and_clean_screen();
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

	wait_and_exit("\nAppuez sur Entree pour quitter...");
}

void coo_yahtzee::game::sort_players() {
	std::sort(players_.begin(), players_.end(), player::compare_player_pointers);
}

void coo_yahtzee::game::display_player_score(const player* p) const {

	std::string eliminate;

	if (p->eliminated_)
		eliminate = " (Elimine)";

	const std::string player = p->c_name_ + eliminate + " : " + std::to_string(p->get_score_result());

	std::cout
		<< "\t| " << std::left << std::setw(38) << player << "|\n";
}