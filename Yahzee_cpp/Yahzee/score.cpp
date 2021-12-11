/* Authors : Frejoux G. & Niord M. */

#include "score.h"

coo_yahtzee::score::score() {

	score_ = 0;

	init_superiors();
	init_inferiors();

	remaining_count_ = inferiors.size() + superiors.size();
}

coo_yahtzee::score::~score()
{
}

void coo_yahtzee::score::init_inferiors() {

	inferiors.reserve(max_inferiors);

	add_inf(new many_of_kind<three_of_kind>("Brelan"));
	add_inf(new many_of_kind<four_of_kind>("Carr�"));
	add_inf(new full_house());
	add_inf(new straight<4>("Petite Suite"));
	add_inf(new straight<5>("Grande Suite"));
	add_inf(new yahtzee());
	add_inf(new many_of_kind<0>("Chance"));

}

void coo_yahtzee::score::init_superiors() {

	superiors.reserve(max_superiors);

	add_sup(new fig_superior<1>());
	add_sup(new fig_superior<2>());
	add_sup(new fig_superior<3>());
	add_sup(new fig_superior<4>());
	add_sup(new fig_superior<5>());
	add_sup(new fig_superior<6>());

}

void coo_yahtzee::score::scored_figure_at(const int& position, const std::vector<dice*>& game) {

	if (position <= remaining_count_)
		set_score(position, game);

	else {

		int new_choice = 0;

		std::cout << "\nOn va dire que ce n'est qu'une simple erreur de frappe...\n";

		display_possibilities(game);

		std::cout << "Quelle combinaison souhaitez-vous inscrire dans votre score ?\n\n";
		std::cin >> new_choice;

		scored_figure_at(new_choice, game);
	}

}

void coo_yahtzee::score::compute_score() {

	score_ = 0;

	for (const figure* sup : superiors)
		if (sup->scored_)
			score_ += sup->score_;

	if (score_ >= bonus_start)
		score_ += bonus;

	for (const figure* inf : inferiors)
		if (inf->scored_)
			score_ += inf->score_;
}

void coo_yahtzee::score::add_inf(figure* inf) {
	superiors.push_back(inf);
}

void coo_yahtzee::score::add_sup(figure* sup) {
	superiors.push_back(sup);
}

void coo_yahtzee::score::set_score(const int& position, const std::vector<dice*>& game) {

	int count = 0;

	for (figure* sup : superiors) {

		if (!sup->scored_)
			count++;

		if (count == position)
			sup->set_score(game);
	}

	for (figure* inf : inferiors) {

		if (!inf->scored_)
			count++;

		if (count == position)
			inf->set_score(game);
	}

	remaining_count_--;

}

void coo_yahtzee::score::score_all() {

	for (figure* sup : superiors)
		sup->elimine();

	for (figure* inf : inferiors)
		inf->elimine();

	compute_score();
}

void coo_yahtzee::score::display_score(std::ostream& out) const {

	out << "\t --------------------------------------------\n"
		<< "\t| Partie superieure    | Score               |\n"
		<< "\t|---------------------------------------------\n";

	for (const figure* sup : superiors) {

		const std::string name = sup->c_name_;
		const auto len = static_cast<int>(name.size());
		const auto score_len = static_cast<int>(std::to_string(sup->score_).size());

		out << "\t| " << name << std::setw(23 - len) << "| " << sup->score_ << std::setw(22 - score_len) << "|\n";
	}

	out << "\t --------------------------------------------\n\n"
		<< "\t --------------------------------------------\n"
		<< "\t| Partie inferieure    | Score               |\n"
		<< "\t|---------------------------------------------\n";

	for (const figure* inf : inferiors) {

		const std::string name = inf->c_name_;
		const auto len = static_cast<int>(name.size());
		const auto score_len = static_cast<int>(std::to_string(inf->score_).size());

		out << "\t| " << name << std::setw(23 - len) << "| " << inf->score_ << std::setw(22 - score_len) << "|\n";
	}

	out << "\t --------------------------------------------\n\n";
}

void coo_yahtzee::score::display_possibilities(const std::vector<dice*>& game) const {

	int count = 1;

	std::cout
		<< " =========== POSSIBILITES ==========\n"
		<< "|                                   |\n";

	std::cout
		<< "| Partie superieure                 |\n"
		<< "|                                   |\n";

	for (const figure* sup : superiors) {

		if (!sup->scored_) {

			const std::string name = sup->c_name_;
			const int preview = sup->get_score_preview(game);
			const auto name_len = static_cast<int>(name.size());
			const auto score_len = static_cast<int>(std::to_string(preview).size());
			const auto count_len = static_cast<int>(std::to_string(count).size());

			std::cout
				<< "| "
				<< count << ". " << name << std::setw(18 - name_len - count_len)
				<< " (" << sup->get_score_preview(game) << ")"
				<< std::setw(14 - score_len) << "|"
				<< std::endl;

			count++;
		}
	}

	std::cout
		<< "|                                   |\n"
		<< "|-----------------------------------|\n";

	std::cout
		<< "| Partie inferieure                 |\n"
		<< "|                                   |\n";

	for (const figure* inf : inferiors) {

		if (!inf->scored_) {

			const std::string name = inf->c_name_;
			const int preview = inf->get_score_preview(game);
			const auto name_len = static_cast<int>(name.size());
			const auto score_len = static_cast<int>(std::to_string(preview).size());
			const auto count_len = static_cast<int>(std::to_string(count).size());

			std::cout
				<< "| "
				<< count << ". " << name << std::setw(18 - name_len - count_len)
				<< " (" << inf->get_score_preview(game) << ")"
				<< std::setw(14 - score_len) << "|"
				<< std::endl;

			count++;
		}
	}

	std::cout
		<< "|                                   |\n"
		<< " ===================================\n\n";
}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const score& s) {
	s.display_score(out);
	return out;
}
