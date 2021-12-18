#include "player.h"

coo_yahtzee::player::player(const std::string& name)
	: c_name_(name) {
	player_score_ = new score();
	eliminated_ = false;
	advertise_count_ = 0;
}

coo_yahtzee::player::~player() {
	delete player_score_;
}

int coo_yahtzee::player::get_score() const {
	return player_score_->score_;
}

int coo_yahtzee::player::advertise_player(const std::string& input) {

	// First there's a verification of the input
	if (check_input_is_integer(input))
		return stoi(input);

	// If the input is incorrect (that means that the player put a letter or a word rather than a number),
	// the program will advertise the player or, simply eliminate the player
	advertise_count_++;

	if (advertise_count_ == max_advertisement - 1)
		std::cout << "\n\n[AVERTISSEMENT] La prochaine fois vous serez elimine... Parce qu'a ce niveau c'est de l'anti-jeu !\n\n";

	else if (advertise_count_ == max_advertisement)
		return 0;

	else
		std::cout << "\n\nMais ??? Le gag classique �a ! \"Gne jve metr des mo et pa des chifr\"...\n\n";

	return -1;
}

void coo_yahtzee::player::score_all() const {
	player_score_->score_all();
}

void coo_yahtzee::player::eliminate() {
	eliminated_ = true;
	score_all();
	std::cout << "\n\nLe joueur " << c_name_ << " a ete elimine.\n\n";
}

int coo_yahtzee::player::player_choice(const int& count) {

	std::string input;
	int menu_count = 0;

	std::cout
		<< " ============= CHOIX ===============\n"
		<< "|                                   |\n"
		<< "|    Que souhaitez - vous faire ?   |\n"
		<< "|                                   |\n";

	if (count < max_round)
		std::cout
			<< "| " << (++menu_count) << ". Relancer ("
			<< (max_round - count) << " coup(s) restant(s))|\n";

	std::cout
		<< "| " << (++menu_count) << ". Inscrire votre score           |\n";

	std::cout
		<< "| " << (++menu_count) << ". jui foutu j'rage quit          |\n"
		<< "|                                   |\n"
		<< " ===================================\n\n"
		<< "Je choisis  : ";

	std::getline(std::cin, input);

	// First the program checks if the input is a number
	const int choice = advertise_player(input);

	// If the input is not a number => loop
	if (choice == -1)
		return player_choice(count);

	// Else if the choice is not contained between expected values => loop
	if (choice < 1 || choice > 3 || (count == 3 && choice > 2)) {
		std::cout << get_error();
		return player_choice(count);
	}

	return choice;
}

void coo_yahtzee::player::player_roll_choice(roll& p_roll) {

	std::string input;

	std::cout
		<< " ============= RELANCE =============\n"
		<< "|                                   |\n"
		<< "| 1. Relancer tous les des          |\n"
		<< "| 2. Choisir mes des                |\n"
		<< "|                                   |\n"
		<< " ===================================\n\n"
		<< "Je choisis : ";

	std::getline(std::cin, input);

	const int choice = advertise_player(input);

	if (choice == 0)
		eliminate();

	else if (choice == -1)
		player_roll_choice(p_roll);

	else {

		std::string selected_dices;

		switch (choice) {

		case 1:
			p_roll.roll_dices();
			break;

		case 2:
			std::cout << p_roll << "\nQuel(s) de(s) souhaitez vous relancer ? (EXEMPLE : 1 5 4)\n\n";
			std::cout << "Le(s) de(s) que je souhaite relancer ";
			std::getline(std::cin, selected_dices);
			p_roll.roll_dice(translate_to_vector(selected_dices));
			break;

		default:
			get_error();
			player_roll_choice(p_roll);
		}
	}

}

void coo_yahtzee::player::player_figure_choice(const roll& p_roll) {

	std::string input;

	player_score_->display_possibilities(p_roll.dices_);

	std::cout << "Quelle combinaison souhaitez-vous inscrire dans votre score ?\n\nLa combinaison ";
	std::getline(std::cin, input);

	// First the program checks if the input is a number
	const int selected_figure = advertise_player(input);

	// If the input is not a number => loop
	if (selected_figure == -1)
		return player_figure_choice(p_roll);

	// If the input is equal to 0 => eliminate the player
	if (selected_figure == 0)
		eliminate();

	// If the input is upper than the maximum given option => message + loop
	if (selected_figure > player_score_->remaining_count_) {
		std::cout << get_error();
		return player_figure_choice(p_roll);
	}

	player_score_->set_score(selected_figure, p_roll.dices_);

}

void coo_yahtzee::player::play_turn(std::vector<dice*>& dices) {
	roll p_roll(dices);
	p_roll.roll_dices();
	std::cout << *player_score_;
	// TODO : attente
	play_round(p_roll);
}

void coo_yahtzee::player::play_round(roll& p_roll) {

	int choice = 0;

	std::cout << p_roll;

	choice = player_choice(p_roll.round_count_);

	// If the round count is equal to 3, then the program needs to increments
	// the returned value from "player_choice" in order to pass the first option
	if (p_roll.round_count_ == max_round)
		choice++;

	switch (choice) {

		case 1 :
			player_roll_choice(p_roll);
			play_round(p_roll);
			break;

		case 2 :
			player_figure_choice(p_roll);
			break;

		default : eliminate();
	}

}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const player&) {
	return out;
}
