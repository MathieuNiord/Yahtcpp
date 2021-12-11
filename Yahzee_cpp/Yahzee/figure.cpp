#include "figure.h"

coo_yahtzee::figure::figure(const std::string& name)
	: c_name_(name) {
	score_ = 0;
	scored_ = false;
}

bool coo_yahtzee::figure::check_figure(const std::vector<dice*>&) const {
	return true;
}

int coo_yahtzee::figure::get_score_preview(const std::vector<dice*>& game) const {

	int score = 0;

	for (const dice* d : game)
		score += d->get_value();

	return score;
}

void coo_yahtzee::figure::set_score(const std::vector<dice*>& game) {
	scored_ = true;
	score_ = get_score_preview(game);
}

void coo_yahtzee::figure::elimine() {
	scored_ = true;
}

std::ostream& coo_yahtzee::figure::to_string(std::ostream& out) const {
	out << c_name_ << " = " << score_;
	return out;
}

std::ostream& coo_yahtzee::figure::preview(std::ostream& out) const {
	out << c_name_ << " (" << score_ << ")";
	return out;
}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const figure& fig) {

	if (!fig.scored_)
		return fig.preview(out);

	return fig.to_string(out);
}