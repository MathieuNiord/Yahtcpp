/* Authors : Frejoux G. & Niord M. */

#include "figure.h"

coo_yahtzee::figure::figure(const std::string& name)
	: c_name_(name) {
	score_ = 0;
	scored_ = false;
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

void coo_yahtzee::figure::eliminate() {
	scored_ = true;
	score_ = 0;
}

std::ostream& coo_yahtzee::figure::to_string(std::ostream& out) const {
	out << c_name_ << " = " << score_;
	return out;
}

std::ostream& coo_yahtzee::operator<<(std::ostream& out, const figure& fig) {
	return fig.to_string(out);
}