/* Authors : Frejoux G. & Niord M. */

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

int coo_yahtzee::player::get_score_result() const {
	return player_score_->score_;
}

int coo_yahtzee::player::advertise_player(const std::string& input) {

	// First there's a verification of the input
	if (check_input_is_integer(input))
		return stoi(input);

	// If the input is incorrect (that means that the player put a letter or a word rather than a number),
	// the program will advertise the player or, simply eliminate the player
	advertise_count_++;

	if (advertise_count_ == max_advertisement)
		return elimination_code;

	if (advertise_count_ == max_advertisement - 1)
		std::cout << "\n\nPROGRAMME : [AVERTISSEMENT] La prochaine fois vous serez elimine... Parce qu'a ce niveau c'est de l'anti-jeu !\n\n";

	else
		std::cout << "\n\nPROGRAMME : Mais ??? Le gag classique ca ! \"Gne jve metr des mo et pa des chifr\"...\n\n";

	return char_error_code;
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
		<< "\t ============= CHOIX ===============\n"
		<< "\t|                                   |\n"
		<< "\t|    Que souhaitez - vous faire ?   |\n"
		<< "\t|                                   |\n";

	if (count < max_round)
		std::cout
		<< "\t| " << (++menu_count) << ". Relancer ("
		<< (max_round - count) << " coup(s) restant(s))|\n";

	std::cout
		<< "\t| " << (++menu_count) << ". Inscrire votre score           |\n";

	std::cout
		<< "\t| " << (++menu_count) << ". jui foutu j'rage quit          |\n"
		<< "\t|                                   |\n"
		<< "\t ===================================\n\n"
		<< "Je choisis  : ";

	std::getline(std::cin, input);

	// First the program checks if the input is a number
	const int choice = advertise_player(input);

	if (choice == elimination_code)
		return elimination_code;

	// If the input is not a number => loop
	if (choice == char_error_code)
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
		<< "\n\t ============= RELANCE =============\n"
		<< "\t|                                   |\n"
		<< "\t| 1. Relancer tous les des          |\n"
		<< "\t| 2. Choisir mes des                |\n"
		<< "\t|                                   |\n"
		<< "\t ===================================\n\n"
		<< "Je choisis : ";

	std::getline(std::cin, input);

	const int choice = advertise_player(input);

	if (choice == elimination_code)
		return eliminate();

	if (choice == char_error_code)
		return player_roll_choice(p_roll);

	std::string selected_dices;

	switch (choice) {

	case 1:
		p_roll.roll_dices();
		break;

	case 2:
		std::cout << p_roll << "\nQuel(s) de(s) souhaitez-vous relancer ? (EXEMPLE : 1 5 4)\n\n";
		std::cout << "Le(s) de(s) que je souhaite relancer ";
		std::getline(std::cin, selected_dices);
		p_roll.roll_dice(translate_to_vector(selected_dices));
        break;

	default:
		get_error();
		return player_roll_choice(p_roll);
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
	if (selected_figure == char_error_code)
		return player_figure_choice(p_roll);

	// If the input is equal to elimination_code => eliminate the player
	if (selected_figure == elimination_code)
		return eliminate();

	// If the input is upper than the maximum given option => message + loop
	if (selected_figure > player_score_->remaining_count_) {
		std::cout << get_error();
		return player_figure_choice(p_roll);
	}

	player_score_->set_score(selected_figure, p_roll.dices_);

}

void coo_yahtzee::player::play_turn(const std::vector<dice*>& dices) {
	roll p_roll(dices);
	std::cout << *player_score_;
	wait_and_clean_screen();
	p_roll.roll_dices();
	play_round(p_roll);
}

void coo_yahtzee::player::play_round(roll& p_roll) {

	int choice = 0;
	std::cout << p_roll;

	player_score_->display_possibilities(p_roll.dices_);

	choice = player_choice(p_roll.round_count_);

	// If the round count is equal to 3, then the program needs to increments
	// the returned value from "player_choice" in order to pass the first option
	if (p_roll.round_count_ == max_round)
		choice++;

	switch (choice) {

	case 1:
		clear_screen();
		player_roll_choice(p_roll);
		if (!eliminated_)
			play_round(p_roll);
		break;

	case 2:
		clear_screen();
		player_figure_choice(p_roll);
		break;

	case 3 :
		eliminate();
		break;

	case elimination_code:
		eliminate();
		break;

	default:
		get_error();
		play_round(p_roll);
	}
}
