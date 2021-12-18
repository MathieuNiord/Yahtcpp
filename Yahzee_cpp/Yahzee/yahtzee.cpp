/* Authors : Frejoux G. & Niord M. */

#include "yahtzee.h"

coo_yahtzee::yahtzee::yahtzee()
	: figure("Yahtzee") {
	count_ = 0;
}

bool coo_yahtzee::yahtzee::check_figure(const std::vector<dice*>& game) const {
	
	std::vector<int> count_values(max_dice_value, 0);

	for (const dice* d : game){

		if (count_values.at(d->get_value() - 1) == number_of_dices)
			return true;

		count_values.at(d->get_value() - 1)++;
	}

	return false;
}

int coo_yahtzee::yahtzee::get_score_preview(const std::vector<dice*>& game) const {

	if (check_figure(game))
		return (count_ + 1) * yahtzee_result;

	return 0;
}

void coo_yahtzee::yahtzee::set_score(const std::vector<dice*>& game) {

	score_ += get_score_preview(game);
	count_++;

	if (count_ == 2)
		scored_ = true;
}